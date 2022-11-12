#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully
 
void solve() {
 int n;
 cin >> n;
 vector<int> nums(n + 2);
 map<int, int> mp;
 long long sum = 0;
 for (int& x : nums) {
  cin >> x;
  ++mp[x];
  sum += x;
 }
 for (int x : nums) {
  long long get = sum - x * 2;
  if (get > 1e9) {
   continue;
  }
  if (mp[get] > (x == get)) {
   int a = find(nums.begin(), nums.end(), x) - nums.begin();
   reverse(nums.begin(), nums.end());
   int b = find(nums.begin(), nums.end(), get) - nums.begin();
   reverse(nums.begin(), nums.end());
   for (int i = 0; i < n + 2; ++i) {
    if (i != a && i != n + 2 - b - 1) {
     cout << nums[i] << ' ';
    }
   }
   cout << '\n';
   return;
  }
 }
 cout << -1 << '\n';
}
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  solve();
 }
}