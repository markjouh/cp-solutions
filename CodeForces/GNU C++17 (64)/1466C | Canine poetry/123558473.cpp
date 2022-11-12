#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 1; i < s.size(); i++) {
   if (s[i] == s[i - 1] || (i > 1 && s[i] == s[i - 2])) {
    s[i] = '0';
    ans++;
   }
  }
  cout << ans << '\n';
 }
}