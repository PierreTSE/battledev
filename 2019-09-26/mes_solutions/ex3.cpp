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

struct pairhash {
public:
    template<typename T, typename U>
    std::size_t operator()(const std::pair<T, U>& x) const {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

void ContestExerciseImpl::main() {
    cin.tie(nullptr);

    ull n;
    cin >> n;
    cin.ignore();
    ull m;
    cin >> m;
    cin.ignore();

    deque<ll> cab;
    prr(i, 1, n)cab.push_front(i);

    vector<pair<ll, ll>> v;
    pr(i, m) {
        ll x, y;
        cin >> x >> y;
        v.eb(x, y);
    }

    //it(e, v) cerr << e << " ";

    sort(bnd(v));

    unordered_map<pair<ll, ll>, ll, pairhash> mem;

    vector<ll> res;

    prr(i, 1, v.back().se) {
        it(e, v) {
            if (e.fi == i) {
                if (cab.empty()) {
                    cout << "pas possible" << endl;
                    goto abort;
                }
                ll x = cab.back();
                res.eb(x);
                mem[e] = cab.back();
                cab.pop_back();
            }
            if (e.se == i) {
                cab.push_front(mem[e]);
            }
        }
    }

    it(e, res)cout << e << " ";


    abort:
    cout << endl;
}