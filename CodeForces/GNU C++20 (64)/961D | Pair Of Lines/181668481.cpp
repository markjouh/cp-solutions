#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pt> p(n);
    for (int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
 
    auto vec = [&](int a, int b) -> pt {
        return {p[b].first - p[a].first, p[b].second - p[a].second};
    };
    auto cross = [](pt a, pt b) -> ll {
        return a.first * b.second - a.second * b.first;
    };
    auto solve = [&](int a, int b) -> bool {
        pt l1 = vec(a, b);
        vector<int> rem;
        for (int i = 0; i < n; i++) {
            if (cross(l1, vec(a, i)) != 0) {
                rem.push_back(i);
            }
        }
        if (sz(rem) < 3) {
            return true;
        }
        pt l2 = vec(rem[0], rem[1]);
        for (int i = 1; i + 1 < sz(rem); i++) {
            if (cross(l2, vec(rem[i], rem[i + 1])) != 0) {
                return false;
            }
        }
        return true;
    };
    
    if (n < 3) {
        cout << "YES\n";
    } else {
        cout << (solve(0, 1) || solve(0, 2) || solve(1, 2) ? "YES\n" : "NO\n");
    }
}