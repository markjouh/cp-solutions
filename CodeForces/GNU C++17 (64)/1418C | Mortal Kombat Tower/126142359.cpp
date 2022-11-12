#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9 + 5;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  vector<vector<int>> dp(n + 1, vector<int>(2, INF));
  dp[0][1] = 0;
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < 2; j++) {
    for (int k = 1; k <= min(2, n - i); k++) {
     int pts = a[i] + (k > 1 ? a[i + 1] : 0);
     dp[i + k][!j] = min(dp[i + k][!j], dp[i][j] + pts * j);
    }
   }
  }
  cout << min(dp[n][0], dp[n][1]) << '\n';
 }
}