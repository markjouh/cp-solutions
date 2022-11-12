#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> nums(n);
  int mn = 1e9;
  for (int &x : nums) {
   cin >> x;
   mn = min(mn, x);
  }
  int ct = 0;
  for (int x : nums) {
   if (x != mn) {
    cout << x << ' ' << mn << '\n';
    ++ct;
   }
   if (ct == n / 2) {
    break;
   }
  }
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 