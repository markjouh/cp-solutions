#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int M = 998244353;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int& x : nums) {
   cin >> x;
  }
  int mx = *max_element(nums.begin(), nums.end());
  int a = count(nums.begin(), nums.end(), mx);
  int b = count(nums.begin(), nums.end(), mx - 1);
  ll ans = 1, sub = 1;
  for (ll i = 2; i <= n; ++i) {
   ans = ans * i % M;
   if (i != b + 1) {
    sub = sub * i % M;
   }
  }
  if (a > 1) {
   // All permutations nice
   cout << ans << '\n';
  } else if (b == 0) {
   // No permutations nice
   cout << 0 << '\n';
  } else {
   // Number of places to order all non a or b, multiplied by number of
   // ways to order all b's such that they all come before a
   cout << (ans - sub + M) % M << '\n';
  }
 }
}