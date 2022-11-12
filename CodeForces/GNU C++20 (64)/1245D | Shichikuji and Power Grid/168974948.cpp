#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
vector<int> sz, par;
 
int get_root(int u) {
    if (par[u] == -1) {
        return u;
    }
    return par[u] = get_root(par[u]);
}
 
void unite(int a, int b) {
    a = get_root(a);
    b = get_root(b);
    if (a == b) {
        return;
    }
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> loc(n);
    for (int i = 0; i < n; i++) {
        cin >> loc[i].fi >> loc[i].se;
    }
    vector<int> c(n), k(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    vector<array<ll, 3>> e;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll d = abs(loc[i].fi - loc[j].fi) + abs(loc[i].se - loc[j].se);
            e.push_back({d * (k[i] + k[j]), i, j});
        }
    }
    for (int i = 0; i < n; i++) {
        e.push_back({c[i], i, n});
    }
    sort(all(e));
 
    sz.resize(n + 1, 1);
    par.resize(n + 1, -1);
 
    ll cost = 0;
    vector<int> pow;
    vector<pair<int, int>> conn;
 
    for (auto [w, u, v] : e) {
        int ru = get_root(u);
        int rv = get_root(v);
        if (ru != rv) {
            if (v == n) {
                pow.push_back(u);
            } else {
                conn.push_back({u, v});
            }
            cost += w;
            unite(ru, rv);
        }
    }
 
    cout << cost << '\n';
 
    cout << pow.size() << '\n';
    for (int x : pow) {
        cout << x + 1 << '\n';
    }
 
    cout << conn.size() << '\n';
    for (auto [u, v] : conn) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
}