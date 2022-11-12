#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully
 
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
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
   long long lg = nums[i], cur = 0;
   vector<int> cnums = nums;
   for (int j = 0; j < n; ++j) {
    if (i != j) {
     while (cnums[j] % 2 == 0) {
      cnums[j] /= 2;
      lg *= 2;
     }
     cur += cnums[j];
    }
   }
   ans = max(ans, lg + cur);
  }
  cout << ans << '\n';
 }
}