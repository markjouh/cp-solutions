#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int &x : nums) {
    cin >> x;
  }
  sort(nums.begin(), nums.end());
  vector<int> ct;
  for (int i = 0; i < 3; ++i) {
    ct.push_back(count(nums.begin(), nums.end(), nums[i]));
  }
  if (nums[0] != nums[1] && nums[1] != nums[2]) {
    cout << 1ll * ct[0] * ct[1] * ct[2] << '\n';
  } else if (nums[0] == nums[1] && nums[1] == nums[2]) {
    cout << 1ll * ct[0] * (ct[0] - 1) * (ct[0] - 2) / 6 << '\n';
  } else if (nums[0] == nums[1]) {
    cout << 1ll * ct[0] * (ct[0] - 1) / 2 * ct[2] << '\n';
  } else {
    cout << 1ll * ct[1] * (ct[1] - 1) / 2 * ct[0] << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Try to think of ideas from past problems
  Check for edge cases, overflow, etc.
*/