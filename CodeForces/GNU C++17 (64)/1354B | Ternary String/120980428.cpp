#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  string s;
  cin >> s;
  int a = -1, b = -1, c = -1, ans = 0;
  for (int i = 0; i < s.size(); i++) {
   if (s[i] == '1') a = i;
   if (s[i] == '2') b = i;
   if (s[i] == '3') c = i;
   if (a != -1 && b != -1 && c != -1) {
    int cur = max({a, b, c}) - min({a, b, c});
    if (cur < ans || ans == 0) ans = cur + 1;
   }
  }
  cout << ans << '\n';
 }
}