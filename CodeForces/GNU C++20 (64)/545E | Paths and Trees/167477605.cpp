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
    vector<ll> ew(m);
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        ew[i] = w;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    int r;
    cin >> r;
    r--;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(n, 1e18);
    pq.push({0, r});
    dist[r] = 0;
    while (sz(pq)) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) {
            continue;
        }
        for (auto [v, id] : g[u]) {
            if (d + ew[id] < dist[v]) {
                dist[v] = d + ew[id];
                pq.push({dist[v], v});
            }
        }
    }
    vector<vector<pair<int, int>>> g1(n);
    for (int u = 0; u < n; u++) {
        for (auto [v, id] : g[u]) {
            if (abs(dist[u] - dist[v]) == ew[id]) {
                g1[u].push_back({v, id});
            }
        }
    }
    g = g1;
    queue<int> q;
    vector<ll> p(n, -1), mn(n, 1e18);
    q.push(r);
    p[r] = r;
    mn[r] = 0;
    while (sz(q)) {
        int u = q.front();
        q.pop();
        for (auto [v, id] : g[u]) {
            if (dist[u] < dist[v] && ew[id] < mn[v]) {
                p[v] = id;
                mn[v] = ew[id];
                q.push(v);
            }
        }
    }
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        tot += mn[i];
    }
    cout << tot << '\n';
    for (int i = 0; i < n; i++) {
        if (i != r) {
            cout << p[i] + 1 << ' ';
        }
    }
}