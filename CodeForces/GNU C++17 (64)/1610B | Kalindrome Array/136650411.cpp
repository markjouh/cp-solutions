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
  vector<int> rem(2);
  for (int i = 0; i < n / 2; ++i) {
   if (nums[i] != nums[n - i - 1]) {
    rem[0] = nums[i];
    rem[1] = nums[n - i - 1];
    break;
   }
  }
  if (rem.empty()) {
   cout << "YES" << '\n';
  }
  bool ok = false;
  for (int i = 0; i < 2; ++i) {
   int l = 0, r = n - 1;
   while (l < r) {
    if (nums[l] == nums[r]) {
     ++l;
     --r;
    }
    if (nums[l] != nums[r]) {
     if (nums[l] == rem[i]) {
      ++l;
     } else if (nums[r] == rem[i]) {
      --r;
     } else {
      break;
     }
    }
   }
   ok |= l >= r;
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
}