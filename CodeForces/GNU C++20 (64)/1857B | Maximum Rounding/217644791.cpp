#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(x...)
#endif
 
typedef long long ll;
 
#define sz(x) static_cast<int>(size(x))
#define all(x) begin(x), end(x)
 
void solve() {
    string s;
    cin >> s;
    const int n = sz(s);
    vector<int> d(n + 1);
    for (int i = 0; i < n; i++) {
        d[i + 1] = s[i] - '0';
    }
 
    int round = n + 1;
    for (int i = n; i >= 1; i--) {
        if (d[i] >= 5) {
            d[i] = 0;
            d[i - 1]++;
            round = i;
        }
    }
    for (int i = round; i <= n; i++) {
        d[i] = 0;
    }
    if (d[0] == 0) {
        d.erase(d.begin());
    }
 
    for (int i = 0; i < sz(d); i++) {
        cout << d[i];
    }
    cout << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}