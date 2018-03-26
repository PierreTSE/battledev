#ifndef IS_IN_FORME_CONV_H
#define IS_IN_FORME_CONV_H

#include <vector>
#include <algorithm>
#include <utility>

template<typename T, typename U>
std::pair<T, U>& operator-(const std::pair<T, U>& lhs, const std::pair<T, U>& rhs)
{
	std::pair<T, U> out(lhs);
	out.first -= rhs.first;
	out.second -= rhs.second;
	return out;
}

template<typename T, typename U>
std::pair<T, U>& operator*(const std::pair<T, U>& lhs, const std::pair<T, U>& rhs)
{
	std::pair<T, U> out(lhs);
	out.first *= rhs.first;
	out.second *= rhs.second;
	return out;
}

bool is_in_forme_conv(const std::pair<double, double>& point, const std::vector<std::pair<double, double>>& forme, const bool avec_aretes)
{
	//std::sort(forme.begin(), forme.end());
	size_t N = forme.size();

	for (unsigned int i = 0; i < N; ++i)
	{
		int j = i % (N - 1);
		auto AB = forme[j + 1] - forme[j];
		auto AC = point - forme[j];
		double p_vectoriel = AB.first*AC.second - AB.second * AC.first;
		if (avec_aretes && p_vectoriel > 0) return false;
		if (!avec_aretes && p_vectoriel >= 0) return false;
	}
	return true;
}

#endif // !IS_IN_FORME_CONV_H
