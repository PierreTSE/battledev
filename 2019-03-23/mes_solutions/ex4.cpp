#include <bits/stdc++.h>
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
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

auto everyStringByDeletingChars(const std::string& str) {
    std::unordered_set<std::string> ens, prev, curr;
    for (size_t i = 0; i < str.size(); ++i) {
        std::string strCopy = str;
        ens.insert(strCopy.erase(i, 1));
    }
    prev = ens;
    while (!prev.empty()) {
        curr.clear();
        for (auto const& s : prev) {
            for (size_t i = 0; i < s.size(); ++i) {
                std::string strCopy = s;
                strCopy.erase(i, 1);
                ens.insert(strCopy);
                curr.insert(strCopy);
            }
        }
        prev = curr;
    }
    return ens;
}

template<typename T>
auto unordered_set_to_sorted_vector(std::unordered_set<T> const& s) {
    std::vector<T> v;
    v.reserve(s.size());
    std::copy(s.begin(), s.end(), std::back_inserter(v));
    sort(v.begin(), v.end());
    return v;
}

template<typename T, template<typename> typename Container>
Container<T> intersection(std::vector<Container<T>> const& vec) {
    return std::accumulate(vec.begin(), vec.end(), vec.front(), [](Container<T> const& a, Container<T> const& b) {
        Container<T> inter;
        std::set_intersection(a.begin(), a.end(),
                              b.begin(), b.end(),
                              std::inserter(inter, inter.begin()));
        return inter;
    });
}

void ContestExerciseImpl::main() {
    cin.tie(nullptr);

    std::string line;
    vector<vector<string>> sets;
    cin >> line;
    cin.ignore();

    while (std::getline(std::cin, line)) {
        unordered_set<string> s = everyStringByDeletingChars(line);
        sets.eb(unordered_set_to_sorted_vector(s));
    }

    auto inter = intersection(sets);

    cout << (inter.size() > 1 ? *max_element(inter.begin(), inter.end(), [](auto const& a, auto const& b) { return a.length() < b.length(); }) : "KO")
         << endl;
}