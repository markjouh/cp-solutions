#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
set<int> factors(int x) {
 set<int> res;
 for (int i = 1; i * i <= x; i++) {
  if (x % i == 0) {
   res.insert(x / i);
   res.insert(i);
  }
 }
 return res;
}
 
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
  int ans = 0;
  for (int i = 0; i < n; i++) {
   int eq = 0;
   vector<int> rem;
   for (int j = 0; j < n; j++) {
    if (nums[i] == nums[j]) {
     eq++;
    } else if (nums[j] > nums[i]) {
     rem.push_back(nums[j] - nums[i]);
    }
   }
   if (eq >= n / 2) {
    ans = 1e9;
    break;
   }
   map<int, int> mp;
   for (int x : rem) {
    for (int y : factors(x)) {
     mp[y]++;
    }
   }
   for (auto p : mp) {
    if (p.second >= n / 2 - eq) {
     ans = max(ans, p.first);
    }
   }
  }
  cout << (ans == 1e9 ? -1 : ans) << '\n';
 }
}