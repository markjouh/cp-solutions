#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
template <class T, class S> inline bool ckmax(T& a, const S& b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool ckmin(T& a, const S& b) { return (a > b ? a = b, 1 : 0); }
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> days(n);
 for (int& i : days) {
  cin >> i;
 }
 vector<vector<int>> dp(n + 1, vector<int>(3));
 for (int i = 0; i < n; ++i) {
  ckmax(dp[i + 1][0], max({dp[i][0], dp[i][1], dp[i][2]}));
  if (days[i] & 1) {
   ckmax(dp[i + 1][1], max(dp[i][0], dp[i][2]) + 1);
  }
  if (days[i] & 2) {
   ckmax(dp[i + 1][2], max(dp[i][0], dp[i][1]) + 1);
  }
 }
 cout << n - *max_element(dp[n].begin(), dp[n].end());
}