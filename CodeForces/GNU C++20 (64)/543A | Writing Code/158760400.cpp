#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define fi first
#define se second
#define sz(a) int(size(a))
#define all(a) begin(a), end(a)
template <typename T> bool umin(T &a, T b) { return (b < a) ? a = b, 1 : 0; }
template <typename T> bool umax(T &a, T b) { return (b > a) ? a = b, 1 : 0; }
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, b, mod;
  cin >> n >> m >> b >> mod;
  vector<vector<int>> dp(m + 1, vector<int>(b + 1));
  dp[0][0] = 1;
  // Looking at values first guarantees ordered results (see coin combinations I vs II)
  for (int i = 0; i < n; i++) {
    int bugs;
    cin >> bugs;
    for (int j = 0; j < m; j++) {
      for (int k = 0; k <= b - bugs; k++) {
        (dp[j + 1][k + bugs] += dp[j][k]) %= mod;
      }
    }
  }
  cout << accumulate(all(dp[m]), 0ll) % mod << '\n';
}