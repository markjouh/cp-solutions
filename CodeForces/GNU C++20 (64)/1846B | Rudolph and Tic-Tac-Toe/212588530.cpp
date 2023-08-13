#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
 
void solve() {
    vector<string> s(3);
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
    }
    vector<set<char>> lines;
    set<char> a, b;
    for (int i = 0; i < 3; i++) {
        a.insert(s[i][i]);
        b.insert(s[i][2 - i]);
        set<char> c, d;
        for (int j = 0; j < 3; j++) {
            c.insert(s[i][j]);
            d.insert(s[j][i]);
        }
        lines.pb(c);
        lines.pb(d);
    }
    lines.pb(a);
    lines.pb(b);
    for (auto st : lines) {
        if (sz(st) == 1 && *st.begin() != '.') {
            cout << *st.begin() << '\n';
            return;
        }
    }
    cout << "DRAW\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}