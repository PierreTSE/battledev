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

int m2s(int m, int s) {
    return m * 60 + s;
}

struct hor {
    int d, f;

    hor(int d, int f) : d(d), f(f) {}

    bool isIn(int t) const {
        return t >= d && t <= f;
    }
};

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    cin.tie(nullptr);

    ull n;
    cin >> n;
    cin.ignore();

    array<vector<hor>, 8> arr;

    pr(i, n) {
        ll x;
        string s;
        cin >> x >> s;

        auto t = split(s, "-");
        int d = m2s(stoi(split(t[0], ":")[0]), stoi(split(t[0], ":")[1]));
        int f = m2s(stoi(split(t[1], ":")[0]), stoi(split(t[1], ":")[1]));
        arr.at(x).eb(d, f);

        cerr << x << " " << s << endl;;
    }

    for (int j = 1; j <= 7; j++) {
        for (int t = 8 * 60; t <= 17 * 60; t++) {
            bool b = true;
            it(e, arr.at(j)) {
                for (size_t delta = 0; delta < 59; ++delta) {
                    if (e.isIn(t + delta)) {
                        b = false;
                        break;
                    }
                }
                if (!b)break;
            }
            if (b) {
                cout << j << " ";
                if (t / 60 < 10)cout << 0;
                cout << t / 60 << ":";
                if (t % 60 < 10)cout << 0;
                cout << t % 60 << "-";
                if ((t + 59) / 60 < 10)cout << 0;
                cout << (t + 59) / 60 << ":";
                if ((t + 59) % 60 < 10)cout << 0;
                cout << (t + 59) % 60;
                return;
            }
        }

    }

    //it(e, v) cerr << e << " ";

    cout << endl;
}