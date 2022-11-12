#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int)(a).size()
 
template <class T, class S> inline bool ckmax(T& a, const S& b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool ckmin(T& a, const S& b) { return (a > b ? a = b, 1 : 0); }
 
const int N = 1e3;
 
int n, m, cnt = 0;
vector<pair<int, int>> g[N][N];
bool vis[N][N];
 
bool bound(int y, int x) {
 return y >= 0 && y < n && x >= 0 && x < m;
}
 
void dfs(int y, int x) {
 vis[y][x] = true;
 ++cnt;
 for (auto [y1, x1] : g[y][x]) {
  if (bound(y1, x1) && !vis[y1][x1]) {
   dfs(y1, x1);
  }
 }
}
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 cin >> n >> m; 
 for (int i = 0; i < n; ++i) {
  for (int j = 0; j < m; ++j) {
   int x;
   cin >> x;
   if (!(x & 8)) g[i][j].push_back({i - 1, j});
   if (!(x & 4)) g[i][j].push_back({i, j + 1});
   if (!(x & 2)) g[i][j].push_back({i + 1, j});
   if (!(x & 1)) g[i][j].push_back({i, j - 1});
  }
 }
 vector<int> res;
 for (int i = 0; i < n; ++i) {
  for (int j = 0; j < m; ++j) {
   if (!vis[i][j]) {
    cnt = 0;
    dfs(i, j);
    res.push_back(cnt);
   }
  }
 }
 sort(rall(res));
 for (int x : res) {
  cout << x << ' ';
 }
}
 