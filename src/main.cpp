//
// Created by thomas on 03/11/17.
// Strengthened by Pierre on 07/11/2018.
//

#include <iostream>
#include "exercise.hpp"
#include <exception>
#include <string>
#include <fstream>
#include "filesystem.hpp"

using namespace std;
namespace fs = std::filesystem;


int main() {
    const fs::path
            path_to_tests(R"(D:\_Programmation\Battle dev\2020-11-26\4)");


    for (auto& p : fs::directory_iterator(path_to_tests.is_absolute() ? path_to_tests : fs::current_path() / path_to_tests)) {
        if (p.path().string().find("output") != string::npos)
            continue;

        int n_test = stoi(p.path().filename().string().substr(p.path().filename().string().find_first_of("0123456789")));

        string input = p.path().string();
        string output = (p.path().parent_path() / fs::path("output" + to_string(n_test) + ".txt")).string();

        ifstream input_file(input.c_str());
        if (!input_file.is_open())
            throw runtime_error("Can't open file : " + input);
        ifstream output_file(output.c_str());
        if (!output_file.is_open())
            throw runtime_error("Can't open file : " + output);


        string expectedResult, line;
        while (getline(output_file, line))
            expectedResult += line += '\n';
        expectedResult.erase(expectedResult.find_last_not_of("\n ") + 1);

        ostringstream out;

        streambuf* inbuf = cin.rdbuf();
        streambuf* outbuf = cout.rdbuf();

        cin.rdbuf(input_file.rdbuf());
        cout.rdbuf(out.rdbuf());

        Exercise* ex = new ContestExerciseImpl;
        ex->main();
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
        delete ex;
        #pragma GCC diagnostic pop

        cin.rdbuf(inbuf);
        cout.rdbuf(outbuf);

        string result = out.str();
        result.erase(result.find_last_not_of("\n ") + 1);

        if (result == expectedResult) { cout << "Le test n " << n_test << " a abouti." << endl << endl; }
        else {
            cout << "Le test n " << n_test << " a failli." << endl << endl;
            cout << "Sortie obtenue :" << result << endl;
            cout << "Sortie attendue :" << expectedResult << endl << endl;
        }
    }

    return 0;
}
