#include <vector>
#include <utility>

template<typename T, typename U>
std::pair<T, U> operator-(const std::pair<T, U>& lhs, const std::pair<T, U>& rhs) {
    return {lhs.first - rhs.first, lhs.second - rhs.second};
}

template<typename T, typename U>
std::pair<T, U> operator*(const std::pair<T, U>& lhs, const std::pair<T, U>& rhs) {
    return {lhs.first * rhs.first, lhs.second * rhs.second};
}

    bool is_in_convex_shape(const std::pair<double, double>& point, const std::vector<std::pair<double, double>>& shape, const bool with_edges = true) {
    const size_t N = shape.size();
    for (unsigned int i = 0; i < N; ++i) {
        size_t j = (i + 1) % N;
        const auto AB = shape[j] - shape[i];
        const auto AC = point - shape[i];
        double p_vectoriel = AB.first * AC.second - AB.second * AC.first;
        if (with_edges && p_vectoriel > 0) return false;
        else if (!with_edges && p_vectoriel >= 0) return false;
    }
    return true;
}
