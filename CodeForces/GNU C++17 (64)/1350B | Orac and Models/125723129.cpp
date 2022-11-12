#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> a(n), dp(n + 1, 1);
  for (int &x : a) {
   cin >> x;
  }
  for (int i = 1; i <= n; i++) {
   for (int j = i * 2; j <= n; j += i) {
    if (a[i - 1] < a[j - 1]) {
     dp[j] = max(dp[j], dp[i] + 1);
    }
   }
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
 }
}