#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 string s;
 cin >> s;
 vector<int> nums;
 int ans = 0;
 for (char c : s) {
  nums.push_back(c - '0');
 }
 int cur = 0;
 set<int> rems = {0};
 for (int x : nums) {
  cur += x;
  if (x == 0 || rems.count(cur % 3)) {
   cur = 0;
   rems = {0};
   ans++;
  } else {
   rems.insert(cur % 3);
  }
 }
 cout << ans << '\n';
}