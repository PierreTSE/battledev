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

auto preprocess(vector<int> const& v) {
    vector<int> pref(v.size(), 0);
    for (size_t i = 1; i < v.size(); ++i) {
        pref[i] = pref[i - 1] ^ v[i];
    }
    return pref;
}

void ContestExerciseImpl::main() {
    cin.tie(nullptr);

    ull n;
    cin >> n;
    ull m;
    cin >> m;

    vector<int> key;
    key.reserve(n);
    pr(i, n) {
        unsigned int x;
        cin >> x;
        key.eb(x);
    }

    auto prefs = preprocess(key);

    vector<int> output(256, 0);

    pr(i, m) {
        int l, r;
        cin >> l >> r;
        if (l == 0) {
            auto base = key[l];
            for (int j = l + 1; j <= r; ++j) {
                base ^= key[j];
            }
            output[base]++;
        } else
            output[prefs[r] ^ prefs[l - 1]]++;
    }

    it(e, output) cout << e << " ";
}