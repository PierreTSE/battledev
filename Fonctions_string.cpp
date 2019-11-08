#include <string>
#include <cctype>
#include <algorithm>

std::string delete_spaces(std::string& str)
{
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	return str;
}

std::vector<std::string> split(const std::string& str, const std::string& sep = " ")
{
	std::vector<std::string> out;
	size_t debut = 0;
	size_t fin = str.find(sep);
	while(debut <= str.length())
    	{
		out.push_back(str.substr(debut, fin - debut));
		debut = fin != std::string::npos ? fin + sep.length() : fin;
		fin = str.find(sep, debut);
    	}
	return out;
}

std::string trim(const std::string& str)
{
	auto pred = [](const unsigned char c) { return std::isspace(c) || std::iscntrl(c); };
	return str.substr(&*std::find_if_not(str.begin(), str.end(), pred) - str.data(), &*std::find_if_not(str.rbegin(), str.rend(), pred) - &*std::find_if_not(str.begin(), str.end(), pred) + 1);
}

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); 
    }
}

