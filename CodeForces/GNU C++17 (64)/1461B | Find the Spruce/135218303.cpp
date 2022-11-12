#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
template<class T> using V = vector<T>;
 
#define rep(i, n) for (int i = 0; i < n; ++i)
#define drep(i, n) for (int i = n - 1; i >= 0; --i)
#define each(a, x) for (auto& a : x)
 
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define srt(a) sort(a.begin(), a.end())
#define dsrt(a) sort(a.rbegin(), a.rend())
 
template <class T, class S> inline bool ckmax(T& a, const S& b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool ckmin(T& a, const S& b) { return (a > b ? a = b, 1 : 0); }
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc; cin >> tc;
 while (tc--) {
  int n, m; cin >> n >> m;
  V<V<int>> pre(n, V<int>(m + 1));
  rep(i, n) rep(j, m) {
   char c; cin >> c;
   pre[i][j + 1] = pre[i][j] + (c == '*');
  }
  ll ans = 0;
  rep(i, n) rep(j, m) {
   int y = i, l = j, r = j + 1;
   while(y < n && l >= 0 && r <= m) {
    if (pre[y][r] - pre[y][l] != r - l) {
     break;
    }
    ++ans;
    ++y; --l; ++r;
   }
  }
  cout << ans << '\n';
 }
}