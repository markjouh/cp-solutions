#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int, int>>> g(n);
    while (q--) {
        int u, v, x;
        cin >> u >> v >> x;
        u--; v--;
        if (u > v) {
            swap(u, v);
        }
        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }
    vector<int> ans(n, (1 << 30) - 1);
 
    // if a vertex is connected to an edge with value 0, it must be off
    for (int i = 0; i < 30; i++) {
        int b = 1 << i;
        for (int u = 0; u < n; u++) {
            for (auto [_, w] : g[u]) {
                if (!(w & b)) {
                    ans[u] -= b;
                    break;
                }
            }
        }
    }
 
    // after that, the result will fufill all the conditions, but we may
    // be able to flip some bits off to make it lexicographically smaller
 
 
    // if the current vertex has value 1, and all its edges and destinations also have value 1, we can switch it off
    for (int u = 0; u < n; u++) {
        for (int i = 0; i < 30; i++) {
            int b = 1 << i;
            if (!(ans[u] & b)) {
                continue;
            }
            bool ok = true;
            for (auto [v, w] : g[u]) {
                if ((!(ans[v] & b) || u == v)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans[u] -= b;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}