#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pt> pos(3);
    for (int i = 0; i < 3; i++) {
        cin >> pos[i].first >> pos[i].second;
    }
    cout << 3 << '\n';
    for (int i = 0; i < 3; i++) {
        pt cur = pos[i];
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                cur.first += pos[j].first - pos[i].first;
                cur.second += pos[j].second - pos[i].second;
            }
        }
        cout << cur.first << ' ' << cur.second << '\n';
    }
}