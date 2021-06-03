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

struct Item {
    double value, weight;
    bool divisible = true;

    Item(double value, double weight, bool divisible = true) : value(value), weight(weight), divisible(divisible) {}
};

double greedyKnapsack(double capacity, vector<Item> items) {
    // sorting Item by decreasing value ratio
    sort(items.rbegin(), items.rend(), [](Item const& a, Item const& b) { return a.value / a.weight < b.value / b.weight; });

    double currWeight = 0;  // Current weight in knapsack
    double finalValue = 0; // Result (value in Knapsack)

    for (auto const& item : items) {
        // If adding Item won't overflow, add it completely
        if (currWeight + item.weight <= capacity) {
            currWeight += item.weight;
            finalValue += item.value;
        }
            // If we can't add current Item, add fractional part of it
        else if (item.divisible) {
            auto remain = capacity - currWeight;
            finalValue += item.value * (remain / item.weight);
            break;
        }
    }

    return finalValue;
}

void ContestExerciseImpl::main() {
    cin.tie(nullptr);

    ull n;
    cin >> n;
    cin.ignore();
    ull m;
    cin >> m;
    cin.ignore();
    ull c;
    cin >> c;
    cin.ignore();

    vector<Item> v; // valeur / poids
    pr(i, n) {
        ll x, y;
        cin >> x >> y;
        v.eb(x, y, false);
    }
    pr(i, m) {
        ll x, y;
        cin >> x >> y;
        v.eb(x * y, y);
    }


    ll maxi = greedyKnapsack(c, v);

    cout << maxi << endl;
}