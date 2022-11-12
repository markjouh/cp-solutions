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
 
const int MAXN = 1e5;
 
int id, cnt;
vector<int> g[MAXN];
int ids[MAXN], low[MAXN], in[MAXN];
bool cont[MAXN];
stack<int> stk;
 
void dfs(int u) {
  stk.push(u);
  cont[u] = true;
  ids[u] = low[u] = id++;
  
  for (int v : g[u]) {
    if (ids[v] == -1) dfs(v);
    if (cont[v]) low[u] = min(low[u], low[v]);
  }
  
  if (ids[u] == low[u]) {
    while (!stk.empty()) {
      int t = stk.top();
      stk.pop();
      cont[t] = false;
      low[t] = ids[u];
      if (t == u) break;
    }
    cnt++;
  }
}
 
const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
 
int cost[MAXN];
int mncost[MAXN], mncostcnt[MAXN];
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  rep(i, 0, n) cin >> cost[i];
  int m;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
  }
  
  rep(i, 0, n) ids[i] = -1;
  rep(i, 0, n) if (ids[i] == -1) dfs(i);
 
  rep(i, 0, n) mncost[i] = INF;
  rep(i, 0, n) mncost[low[i]] = min(mncost[low[i]], cost[i]);
  rep(i, 0, n) {
    if (cost[i] < mncost[low[i]]) {
      mncost[low[i]] = cost[i];
      mncostcnt[low[i]] = 0;
    }
    if (cost[i] == mncost[low[i]]) mncostcnt[low[i]]++;
  }
 
  ll ans = 0, ways = 1;
  rep(i, 0, n) {
    if (mncost[i] != INF) {
      ans += mncost[i];
      ways = ways * mncostcnt[i] % MOD;
    }
  }
  cout << ans << ' ' << ways << '\n';
}