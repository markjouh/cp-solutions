#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<vector<int>> t(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        t[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> t[i][j];
        }
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(n, 1e18);
    pq.push({0, 0});
    dist[0] = 0;
    while (sz(pq)) {
        auto [p, u] = pq.top();
        pq.pop();
        if (p > dist[u]) {
            continue;
        }
        int idx = 0;
        while (idx < sz(t[u]) && t[u][idx] < p) {
            idx++;
        }
        int wait = 0;
        while (idx + wait < sz(t[u]) && t[u][idx + wait] == p + wait) {
            wait++;
        }
        p += wait;
        for (auto [v, w] : g[u]) {
            if (p + w < dist[v]) {
                dist[v] = p + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << (dist[n - 1] == 1e18 ? -1 : dist[n - 1]) << '\n';
}