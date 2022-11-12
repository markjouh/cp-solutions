#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int arr[2][400000];
map<int, int> g, visited;
 
int dfs(int origin, int node) {
 if (visited[node]) {
  return 0;
 }
 if (g[node] == origin) {
  return 1;
 }
 visited[node] = true;
 return dfs(origin, g[node]);
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
   cin >> arr[0][i];
  }
  for (int i = 0; i < n; i++) {
   cin >> arr[1][i];
  }
  for (int i = 0; i < n; i++) {
   g[arr[0][i]] = arr[1][i];
  }
  int cnt = 0;
  for (auto x : g) {
   cnt += dfs(x.first, x.first);
  }
  long long ans = 1;
  for (int i = 0; i < cnt; i++) {
   ans = ans * 2ll % MOD;
  }
  cout << ans << '\n';
  g.clear();
  visited.clear();
 }
}