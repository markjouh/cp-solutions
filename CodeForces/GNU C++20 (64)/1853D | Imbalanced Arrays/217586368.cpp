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
    int n;
    cin >> n;
    vector<vector<int>> a_ind(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a_ind[x].push_back(i);
    }
 
    vector<int> ans(n);
    bool ok = true;
    int pos_greater = 0;
    for (int i = n; i >= 1; i--) {
        if (sz(a_ind[pos_greater]) > 0 && sz(a_ind[i + pos_greater]) == 0) {
            ans[a_ind[pos_greater].back()] = -i;
            a_ind[pos_greater].pop_back();
        } else if (sz(a_ind[pos_greater]) == 0 && sz(a_ind[i + pos_greater]) > 0) {
            ans[a_ind[i + pos_greater].back()] = i;
            a_ind[i + pos_greater].pop_back();
            pos_greater++;
        } else {
            ok = false;
            break;
        }
    }
 
    if (ok) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    } else {
        cout << "NO\n";
    }
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