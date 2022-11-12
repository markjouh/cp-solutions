#include <bits/stdc++.h>
using namespace std;
 
bool ckeven(char c) {
 return c == '0' || c == '2' || c == '4' || c == '6' || c == '8';
}
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  string s;
  cin >> s;
  bool ok = false;
  for (char c : s) {
   ok |= ckeven(c);
  }
  if (!ok) {
   cout << -1 << '\n';
   continue;
  }
  if (ckeven(s[s.size() - 1])) {
   cout << 0 << '\n';
  } else if (ckeven(s[0])) {
   cout << 1 << '\n';
  } else {
   cout << 2 << '\n';
  }
 }
}