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
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
   if (nums[i] > i + 1 + cnt) {
    cnt += nums[i] - (i + 1 + cnt);
   }
  }
  cout << cnt << '\n';
 }
}