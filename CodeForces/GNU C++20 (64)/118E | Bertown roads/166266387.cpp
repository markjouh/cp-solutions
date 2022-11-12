#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
 
#define rep(i, a, n) for (int i = 0; i < (int)n; i++)
#define per(i, a, n) for (int i = 0; i < (int)n; i++)
#define fi first
#define se second
#define pb push_back
 
const int sz = 1e5;
 
vector<pair<int, int>> adj[sz];
bool bridge;
int timer;
int entry[sz], low[sz];
bool vis[sz];
pii orient[3 * sz];
 
void dfs(int u, int p = -1) {
  vis[u] = true;
  entry[u] = low[u] = timer++;
  for (auto [v, id] : adj[u]) {
    if (v == p) continue;
    if (orient[id].fi == 0 && orient[id].se == 0) {
      orient[id] = {u, v};
    }
    if (vis[v]) {
      low[u] = min(low[u], entry[v]);
    } else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > entry[u]) {
        bridge = true;
        return;
      }
    }
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    adj[u].pb({v, i});
    adj[v].pb({u, i});
  }
  dfs(0);
  if (bridge) {
    cout << 0;
  } else {
    rep(i, 0, m) {
      cout << orient[i].fi + 1 << ' ' << orient[i].se + 1 << '\n';
    }
  }
}
 
/*
1: Check if the graph has bridges. If it does, there is no strong orientation.
2: Otherwise, run DFS on the graph, orienting DFS tree edges away from the root
   and all other edges from the descendant to the ancestor.
*/