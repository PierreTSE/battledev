#include <bits/stdc++.h>

using namespace std;

struct Point {
    Point() = default;

    Point(size_t x, size_t y) : x{x}, y{y} {}

    size_t x = 0, y = 0;
};

double dist(Point const& a, Point const& b) {
    return hypot(a.x - b.x, a.y - b.y);
}


template<typename T>
struct Matrix {
    size_t height, width;
    std::vector<T> d;

    Matrix(size_t height, size_t width) : height(height), width(width) {
        d.reserve(width * height);
    }

    Matrix(size_t height, size_t width, T t) : height(height), width(width) {
        d = vector<T>(height * width, t);
    }

    explicit Matrix(size_t size) : height(size), width(size) {
        d.reserve(size * size);
    }

    T const& operator()(size_t i, size_t j) const noexcept {
        return d.at(i * width + j);
    }

    T& operator()(size_t i, size_t j) noexcept {
        return d.at(i * width + j);
    }

    [[nodiscard]] bool is_inside(size_t i, size_t j) const {
        return i >= 0 && j >= 0 && i < height && j < width;
    }

    [[nodiscard]] std::pair<size_t, size_t> idx2coords(size_t idx) const {
        return {idx / width, idx % width};
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const Matrix<T>& m) {
    for (size_t i = 0; i < m.height; ++i) {
        for (size_t j = 0; j < m.width; ++j) {
            o << m(i, j) << " ";
        }
        o << endl;
    }
    return o;
}

template<typename T>
std::istream& operator>>(std::istream& o, Matrix<T>& m) {
    for (size_t i = 0; i < m.height; ++i) {
        for (size_t j = 0; j < m.width; ++j) {
            o >> m(i, j);
        }
    }
    return o;
}

#include "exercise.hpp"

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
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    Matrix m(20, 10, '.');

    cin >> m;


    for (int i = m.height; i --> 0;) {
        for (int j = 0; j < m.width; ++j) {
            if (m(i, j) == '.') {
                bool b = true;
                int k;
                for ( k = 0; k <= i; ++k) {
                    if (m(k, j) != '.') {
                        b = false;
                        break;
                    }
                }
                if (b && k>=4) {
                    bool b = true;
                    for (int l = 0; l < m.width; ++l) {
                        if(l==j) continue;
                        if(m(i,l)!='#'){
                            b=false;
                            break;
                        }
                    }
                    if(b && (i == m.height-1 || m(i+1,j)=='#')){
                    cout << "BOOM " << j+1 << endl;
                    return;
                    }
                }
            }
        }
    }

    cout << "NOPE" << endl;
}