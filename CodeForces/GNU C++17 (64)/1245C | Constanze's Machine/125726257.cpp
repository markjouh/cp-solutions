#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 1e9 + 7;
const auto no = string::npos;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 string s;
 cin >> s;
 if (s.find('w') != no || s.find('m') != no) {
  cout << 0 << '\n';
  return 0;
 }
 vector<int> dp(s.size() + 1);
 dp[0] = dp[1] = 1;
 for (int i = 2; i <= s.size(); i++) {
  dp[i] = dp[i - 1];
  if (s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n')) {
   dp[i] = (dp[i - 1] + dp[i - 2]) % M;
  }
 }
 cout << dp[s.size()] << '\n';
}