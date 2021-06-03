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

void ContestExerciseImpl::main() {
    cin.tie(nullptr);

    ull n;
    cin >> n;
    cin.ignore();

    vector <ll> v;
    ll s = 0;
    pr(i, n) {
        ll x, y;
        cin >> x;
        //v.eb(x);
    }

    //it(e, v) cerr << e << " ";

    cout << endl;
}