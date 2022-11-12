#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int n;
 string s;
 cin >> n >> s;
 if (count(s.begin(), s.end(), '(') != count(s.begin(), s.end(), ')')) {
  cout << -1 << '\n';
  return 0;
 }
 int cnt = 0, ans = 0;
 for (char c : s) {
  cnt += (c == '(' ? 1 : -1);
  if (cnt < 0 || (cnt == 0 && c == '(')) {
   ans++;
  }
 }
 cout << ans << '\n';
} 