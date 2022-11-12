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
  vector<int> nums(n);
  for (int& v : nums) {
   cin >> v;
  }
  sort(nums.begin(), nums.end(), greater<int>());
  int add = 0;
  while (nums.size() > 1 && nums.back() + add <= 0) {
   add -= nums.back() + add;
   nums.pop_back();
  }
  int ans = -1e9;
  reverse(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); ++i) {
   nums[i] += add;
  }
  nums.insert(nums.begin(), 0);
  for (int i = 1; i < nums.size(); ++i) {
   ans = max(ans, nums[i] - nums[i - 1]);
  }
  cout << ans << '\n';
 }
}