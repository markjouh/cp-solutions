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
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        deg[u]++;
        deg[v]++;
    }
    vector<pii> cnt(n);
    for (int i = 0; i < n; i++) {
        cnt[i].se = i;
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] != 1) {
            cnt[deg[i]].fi++;
        }
    }
    sort(all(cnt));
    reverse(all(cnt));
    if (cnt[1].fi == 0) {
        cout << cnt[0].se << ' ' << cnt[0].se - 1 << '\n';
    } else {
        cout << cnt[1].se << ' ' << cnt[0].se - 1 << '\n';
    }
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