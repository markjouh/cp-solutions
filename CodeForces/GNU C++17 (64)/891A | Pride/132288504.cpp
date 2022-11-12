#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> nums(n);
 int ones = 0;
 for (int& x : nums) {
  cin >> x;
  ones += x == 1;
 }
 
 int best = 1e9;
 for (int i = 0; i < n - 1; i++) {
  int l = 0, r = i;
  int GCD = nums[r];
  while (GCD != 1 && r < n - 1) {
   r++;
   GCD = gcd(GCD, nums[r]);
  }
  if (GCD != 1) {
   continue;
  }
  GCD = nums[r];
  l = r;
  while (GCD != 1 && l > 0) {
   l--;
   GCD = gcd(GCD, nums[l]);
  }
  best = min(best, r - l);
 }
 
 if (best == 1e9 && ones == 0) {
  cout << -1 << '\n';
 } else if (ones > 0) {
  cout << n - ones << '\n';
 } else {
  cout << best + n - 1 << '\n';
 }
}