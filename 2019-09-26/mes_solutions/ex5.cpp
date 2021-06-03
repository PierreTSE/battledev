#include <bits/stdc++.h>
#include "../../src/exercise.hpp"
#define prr(i, a, b) for(int i = (a); i <= (b); i++)
#define rpr(i, a, b) for(int i = (b); i --> (a);)
#define pr(i, b) for(size_t i = 0; i < (b); i++)
#define it(e, c)   for(auto e : c)
#define rit(e, c)  for(auto& e : c)
#define bnd(a) a.begin(), a.end()
#define rbnd(a) a.rbegin(), a.rend()
#define ina(n, a) cin >> n; pr(0,n) cin >> a[i]
#define cr const&
#define sz(x) (x).size()
#define len(x) (x).length()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define pcnt __builtin_popcountll
#define MOD 1000000007
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

int random(int min, int max) {
#if defined(WIN32) && (defined(__GNUC__) || defined(__GNUG__))
    static std::default_random_engine eng(std::time(nullptr));
#else
    static std::default_random_engine eng(std::random_device{}());
#endif
    std::uniform_int_distribution<int> distrib(min, max);
    return distrib(eng);
}

std::vector<std::string> split(const std::string& str, const std::string& sep = " ") {
    std::vector<std::string> out;
    size_t debut = 0;
    size_t fin = str.find(sep);
    while (debut <= str.length()) {
        out.push_back(str.substr(debut, fin - debut));
        debut = fin != std::string::npos ? fin + sep.length() : fin;
        fin = str.find(sep, debut);
    }
    return out;
}

void ContestExerciseImpl::main() {
    cin.tie(nullptr);

    char n;
    cin >> n;
    cin.ignore();

    set<string> ss;
    pr(i, 21) {
        string s;
        getline(cin, s);
        auto v = split(s);
        ss.insert(v.at(0));
        ss.insert(v.at(1));
    }

    //it(e, v) cerr << e << " ";

    vector<string> v;
    std::copy(bnd(ss), back_inserter(v));

    cout << v.at(random(0, v.size() - 1)) << endl;
}