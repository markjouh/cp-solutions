#include <bits/stdc++.h>
using namespace std;
 
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
  if (nums[0] != n && nums[n - 1] != n) {
   cout << -1 << '\n';
   continue;
  }
  reverse(nums.begin(), nums.end());
  for (int x : nums) {
   if (x != n) {
    cout << x << ' ';
   }
  }
  cout << n;
  cout << '\n';
 }
}