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
  bool ok = true;
  for (int i = 0; i < min(21, n); ++i) {
   bool cur = false;
   for (int j = 2; j <= i + 2; ++j) {
    cur |= nums[i] % j;
   }
   ok &= cur;
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
}