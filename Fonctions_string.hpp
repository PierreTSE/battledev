#ifndef FONCTIONS_STRING_H
#define FONCTIONS_STRING_H

#include <string>
#include <cctype>
#include <algorithm>

std::string delete_spaces(std::string& str)
{
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	return str;
}

std::vector<std::string> separe_mots(std::string str)
{
	std::vector<std::string> v_out;
	auto debut = str.find_first_not_of(' ');
	auto fin = str.find_first_of(' ', debut);
	while (debut != std::string::npos)
	{
		v_out.push_back(str.substr(debut, fin - debut));
		debut = str.find_first_not_of(' ', fin);
		fin = str.find_first_of(' ', debut);
	}
	return v_out;
}

#endif // !FONCTIONS_STRING_H

