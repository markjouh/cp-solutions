#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  string s;
  cin >> s;
  long long ans = 0;
  int cnt1 = 0, cnt2 = 0, state = 0;
  for (char c : s) {
   if (c - '0' == state || c == '?') {
    cnt1++;
   } else {
    cnt1 = 0;
   }
   if (c - '0' == (state ^ 1) || c == '?') {
    cnt2++;
   } else {
    cnt2 = 0;
   }
   ans += max(cnt1, cnt2);
   state ^= 1;
  }
  cout << ans << '\n';
 }
}