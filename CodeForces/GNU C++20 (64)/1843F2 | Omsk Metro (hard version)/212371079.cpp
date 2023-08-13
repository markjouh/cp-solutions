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
 
const int lg = 17;
 
struct Data {
    int sum, pref_mn, pref_mx, suf_mn, suf_mx, seg_mn, seg_mx;
    Data(int x = 0) {
        sum = x;
        pref_mn = suf_mn = seg_mn = min(x, 0);
        pref_mx = suf_mx = seg_mx = max(x, 0);
    }
};
 
Data merge(Data &a, Data &b) {
    Data ret;
    ret.sum = a.sum + b.sum;
    ret.pref_mn = min(a.pref_mn, a.sum + b.pref_mn);
    ret.pref_mx = max(a.pref_mx, a.sum + b.pref_mx);
    ret.suf_mn = min(a.suf_mn + b.sum, b.suf_mn);
    ret.suf_mx = max(a.suf_mx + b.sum, b.suf_mx);
    ret.seg_mn = min({a.seg_mn, a.suf_mn + b.pref_mn, b.seg_mn});
    ret.seg_mx = max({a.seg_mx, a.suf_mx + b.pref_mx, b.seg_mx});
    return ret;
}
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> up(lg + 1, vector<int>(n + 1));
    vector<vector<Data>> ans(lg + 1, vector<Data>(n + 1));
    ans[0][0] = Data(1);
    vector<int> dep(n + 1);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            int v, x;
            cin >> v >> x;
            v--;
            cur++;
            dep[cur] = dep[v] + 1;
            up[0][cur] = v;
            ans[0][cur] = Data(x);
            for (int j = 0; j < lg; j++) {
                up[j + 1][cur] = up[j][up[j][cur]];
                ans[j + 1][cur] = merge(ans[j][cur], ans[j][up[j][cur]]);
            }
        } else {
            int u, v, k;
            cin >> u >> v >> k;
            u--; v--;
            if (dep[u] < dep[v]) {
                swap(u, v);
            }
            int diff = dep[u] - dep[v];
            Data u_path, v_path;
            for (int j = lg; j >= 0; j--) {
                if ((diff >> j) & 1) {
                    u_path = merge(u_path, ans[j][u]);
                    u = up[j][u];
                }
            }
            if (u == v) {
                u_path = merge(u_path, ans[0][u]);
            } else {
                for (int j = lg; j >= 0; j--) {
                    if (up[j][u] != up[j][v]) {
                        u_path = merge(u_path, ans[j][u]);
                        u = up[j][u];
                        v_path = merge(v_path, ans[j][v]);
                        v = up[j][v];
                    }
                }
                u_path = merge(u_path, ans[1][u]);
                v_path = merge(v_path, ans[0][v]);
            }
            swap(v_path.pref_mn, v_path.suf_mn);
            swap(v_path.pref_mx, v_path.suf_mx);
            Data res = merge(u_path, v_path);
            if (res.seg_mn <= k && k <= res.seg_mx) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
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