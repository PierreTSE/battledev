#include <bits/stdc++.h>
#include <ostream>
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

enum Type {
    feu, eau, pla, gla, poi, sol, vol
};

struct Pok {
    Type type;

    Pok(string const& s) {
        if (s == "plante") {
            type = pla;
        } else
            switch (s[0]) {
                case 'f':type = feu;
                    break;
                case 'e':type = eau;
                    break;
                case 'g':type = gla;
                    break;
                case 'p':type = poi;
                    break;
                case 's':type = sol;
                    break;
                case 'v':type = vol;
                    break;
            }
    }

    bool win(Type rhs) {
        switch (type) {
            case feu: {
                switch (rhs) {
                    case pla:
                    case gla:return true;
                    default:return false;
                }
            }
                break;
            case eau: {
                switch (rhs) {
                    case feu:return true;
                    default:return false;
                }
            }
                break;
            case pla: {
                switch (rhs) {
                    case eau:
                    case vol:
                    case poi:return true;
                    default:return false;
                }
            }
                break;
            case gla: {
                switch (rhs) {

                    default:return false;
                }
            }
                break;
            case poi: {
                switch (rhs) {

                    default:return false;
                }
            }
                break;
            case sol: {
                switch (rhs) {
                    case eau:
                    case pla:return true;
                    default:return false;
                }
            }
                break;
            case vol: {
                switch (rhs) {

                    default:return false;
                }
            }
                break;
        }
    }

    bool operator<(const Pok& rhs) const {
        return type < rhs.type;
    }

    friend ostream& operator<<(ostream& os, const Pok& pok) {
        switch (pok.type) {

            case feu:os << "feu";
                break;;
            case eau:os << "eau";
                break;;
            case pla:os << "plante";
                break;;
            case gla:os << "glace";
                break;;
            case poi:os << "poison";
                break;;
            case sol:os << "sol";
                break;;
            case vol:os << "vol";
                break;;
        }
        return os;
    }
};

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

bool battle(vector<Pok> moi, vector<Pok> lui) {
    while (!moi.empty() && !lui.empty()) {
        if (moi.back().win(lui.back().type)) {
            lui.pop_back();
        } else {
            if (lui.back().win(moi.back().type)) {
                moi.pop_back();
            } else {
                lui.pop_back();
                moi.pop_back();
            }
        }
    }
    return !moi.empty() && lui.empty();
}

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    cin.tie(nullptr);

    ull n;
    cin >> n;
    cin.ignore();

    vector<Pok> moi;
    vector<Pok> lui;

    string s;

    getline(cin, s);
    auto v = split(s);
    it(e, v)lui.eb(e);
    reverse(bnd(lui));

    getline(cin, s);
    v = split(s);
    it(e, v)moi.eb(e);
    sort(bnd(moi));

    bool won = false;
    do {
        won = battle(moi, lui);
    } while (!won && std::next_permutation(bnd(moi)));

    if (!won) {
        cout << -1;
        return;
    }

    it(e, moi)cout << e << " ";
    cout << endl;
}