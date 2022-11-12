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
  int cnt = count(s.begin(), s.end(), '1');
  if (cnt % 2 || s[0] == '0' || s[n - 1] == '0') {
   cout << "NO" << '\n';
   continue;
  }
  string a, b;
  bool state = false;
  int cur = 0;
  for (int i = 0; i < n; i++) {
   if (s[i] == '1') {
    a += (2 * cur < cnt ? '(' : ')');
    b += a.back();
    cur++;
   } else {
    a += (state ? '(' : ')');
    b += (state ? ')' : '(');
    state = !state;
   }
  }
  cout << "YES" << '\n' << a << '\n' << b << '\n';
 }
}