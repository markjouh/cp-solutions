#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.tie(0);
 cin.sync_with_stdio(0);
 int tc;
 cin >> tc;
 while (tc--) {
  string s, t;
  cin >> s >> t;
  int ptr = 0;
  bool skip = false;
  for (int i = (s.size() + t.size()) & 1; i < s.size(); i++) {
   if (skip) {
    skip = false;
    continue;
   }
   if (s[i] == t[ptr]) {
    ptr++;
   } else {
    skip = true;
   }
  }
  cout << (ptr == t.size() ? "YES" : "NO") << '\n';
 }
}