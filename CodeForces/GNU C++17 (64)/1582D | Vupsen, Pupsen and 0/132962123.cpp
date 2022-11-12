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
  for (int& x : nums) {
   cin >> x;
  }
  int start = 0;
  if (n % 2) {
   if (nums[0] + nums[1]) {
    cout << -nums[2] << ' ' << -nums[2] << ' ' << nums[0] + nums[1] << ' ';
   } else if (nums[0] + nums[2]) {
    cout << -nums[1] << ' ' << nums[0] + nums[2] << ' ' << -nums[1] << ' ';
   } else {
    cout << nums[1] + nums[2] << ' ' << -nums[0] << ' ' << -nums[0] << ' ';
   }
   start = 3;
  }
  for (int i = start; i < n; i += 2) {
   cout << nums[i + 1] << ' ' << -nums[i] << ' ';
 
  }
  cout << '\n';
 }
}