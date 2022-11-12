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
  int mn = 1e9;
  for (int& x : nums) {
   cin >> x;
   mn = min(mn, x);
  }
  int ans = 0;
  for (int x : nums) {
   if (x - mn > 0) {
    ans = gcd(ans, x - mn);
   }
  }
  cout << (ans == 0 ? -1 : ans) << '\n';
 }
}