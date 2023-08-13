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
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
 
    auto f = [&](int i) {
        return (i + n) % n;
    };
 
    bool has_edge = false, is_cycle = true;
    for (int i = 0; i < n; i++) {
        has_edge |= t[i] != t[f(i + 1)];
        is_cycle &= t[i] != t[f(i + 1)];
    }
 
    if (!has_edge) {
        cout << 1 << '\n';
        for (int i = 0; i < n; i++) {
            cout << 1 << ' ';
        }
        cout << '\n';
        return;
    }
 
    if (!is_cycle) {
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            if (t[i] == t[f(i - 1)]) {
                int ind = i;
                ans[ind] = 1;
                while (t[ind] != t[f(ind + 1)] && ans[f(ind + 1)] == -1) {
                    ans[f(ind + 1)] = 3 - ans[ind];
                    ind = f(ind + 1);
                }
            }
        }
 
        cout << 2 << '\n';
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
 
    vector<int> ans(n, 1);
    for (int i = 1; i < n; i += 2) {
        ans[i] = 2;
    }
    if (n % 2) {
        ans[0] = 3;
    }
    cout << 2 + n % 2 << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
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
 
/*
 
It's something related to bipartiteness/graph coloring
Let's try connecting an edge between types u and v if they are adjacent and of different types
 
We always use at least one color
If there exist any edges, we use 2 colors
If the graph has an odd cycle (not bipartite), we can use 3 colors
 
Since the graph consists of a set of bamboo trees and cycle graphs, these cases cover everything.
 
*/