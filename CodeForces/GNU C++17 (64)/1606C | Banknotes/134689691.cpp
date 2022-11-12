#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
// cloudcloud
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr); 
 vector<int> p10(10);
 p10[0] = 1;
 for (int i = 1; i < 10; ++i) {
  p10[i] = p10[i - 1] * 10;
 }
 int tc;
 cin >> tc;
 while (tc--) {
  int n, k;
  cin >> n >> k;
  ++k; // Must be strictly not representable by k notes
  vector<int> nums(n);
  for (int& x : nums) {
   cin >> x;
  }
  sort(nums.begin(), nums.end());
  ll ans = 0;
  for (int i = 0; i < n - 1; ++i) {
   int cur = p10[nums[i + 1] - nums[i]] - 1;
   ans += min(k, cur) * (ll)p10[nums[i]];
   k -= min(k, cur);
  }
  ans += k * (ll)p10[nums.back()];
  cout << ans << '\n';
 }
}