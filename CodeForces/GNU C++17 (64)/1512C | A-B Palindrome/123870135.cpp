#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int a, b;
  string s;
  cin >> a >> b >> s;
  a -= count(s.begin(), s.end(), '0');
  b -= count(s.begin(), s.end(), '1');
  int n = s.size();
  for (int i = 0; i < n / 2; i++) {
   if (s[i] == '?' && s[n - i - 1] != '?') {
    s[i] = s[n - i - 1];
    (s[n - i - 1] == '0' ? a : b)--;
   } else if (s[i] != '?' && s[n - i - 1] == '?') {
    s[n - i - 1] = s[i];
    (s[i] == '0' ? a : b)--;
   }
  }
  bool ok = true;
  for (int i = 0; i < n / 2; i++) {
   if (s[i] == '?' && s[n - i - 1] == '?') {
    if (a > b) {
     s[i] = '0';
     s[n - i - 1] = '0';
     a -= 2;
    } else {
     s[i] = '1';
     s[n - i - 1] = '1';
     b -= 2;
    }
   } else if (s[i] != s[n - i - 1]) {
    ok = false;
    break;
   }
  }
  if (n % 2 && s[n / 2] == '?') {
   s[n / 2] = (a > b ? '0' : '1');
   (a > b ? a : b)--;
  }
  cout << (ok && a >= 0 && b >= 0 ? s : "-1") << '\n';
 }
}