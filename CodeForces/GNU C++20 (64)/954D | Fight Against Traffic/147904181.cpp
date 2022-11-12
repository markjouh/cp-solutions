#include <bits/stdc++.h>
using namespace std;
 
#define pf push_front
#define pb push_back
#define rf pop_front
#define rb pop_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rep(i,a,b) for (int i = a; i < b; i++)
#define per(i,a,b) for (int i = b-1; i >= a; i--)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<int> g[n+1];
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  int dist[n+1][n+1]{};
  rep(i, 1, n+1) {
    bool seen[n+1]{};
    queue<pair<int, int>> q;
    q.push({i, 0});
    while (sz(q)) {
      int u = q.front().first;
      int d = q.front().second;
      q.pop();
      if (seen[u]) {
        continue;
      }
      seen[u] = true;
      dist[i][u] = d;
      for (int v : g[u]) {
        if (!seen[v]) {
          q.push({v, d+1});
        }
      }
    }
  }
  int ans = 0;
  int mndist = dist[s][t];
  rep(i, 1, n+1) {
    rep(j, i+1, n+1) {
      if (dist[i][j] > 1 && min(dist[s][i]+dist[t][j], dist[s][j]+dist[t][i])+1 >= mndist) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
}