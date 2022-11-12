#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  string s;
  cin >> n >> s;
  string a, b, c;
  for (int i = 0; i < n; i++) {
   if (s[i] == '0') {
    a += '0';
   } else break;
  }
  for (int i = n - 1; i >= 0; i--) {
   if (s[i] == '1') {
    c += '1';
   } else break;
  }
  if (count(s.begin(), s.end(), '0') > a.size()) {
   b = '0';
  } else if (count(s.begin(), s.end(), '1') > c.size()) {
   b = '1';
  }
  cout << a + b + c << '\n';
 }
}