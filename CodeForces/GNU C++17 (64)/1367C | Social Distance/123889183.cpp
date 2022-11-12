#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  string s;
  cin >> n >> k >> s;
 
  auto pts = [&](int len) {
   int res = 0;
   while (res + 1 + max(0, res) * k <= len) {
    res++;
   }
   return res;
  };
 
  int ans = 0, len = 0;
  bool flag = false;
  for (char c : s) {
   if (c == '1') {
    ans += pts(len - k - flag * k);
    flag = true;
    len = 0;
   } else {
    len++;
   }
  }
  ans += pts(len - flag * k);
  cout << ans << '\n';
 }
}