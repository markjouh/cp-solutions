#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  vector<int> nums(3);
  int sum = 0;
  for (int&x : nums) {
   cin >> x;
   sum += x;
  }
  int m;
  cin >> m;
  bool ok = true;
  ok &= nums[0] + nums[1] + nums[2] - 3 >= m;
  for (int i = 0; i < 3; ++i) {
   ok &= nums[i] - (sum - nums[i]) - 1 <= m;
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
}