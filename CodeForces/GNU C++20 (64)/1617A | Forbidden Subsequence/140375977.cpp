#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int T;
 cin >> T;
 while (T--) {
  string s, t;
  cin >> s >> t;
  vector<int> ct(3);
  string rem;
  for (char c : s) {
   if (c == 'a' || c == 'b' || c == 'c') {
    ct[c - 'a']++;
   } else {
    rem += c;
   }
  }
  if (t != "abc" || ct[0] == 0 || ct[1] == 0 || ct[2] == 0) {
   sort(s.begin(), s.end());
   cout << s << '\n';
   continue;
  }
  for (int i = 0; i < ct[0]; i++) {
   cout << 'a';
  }
  if (t[1] == 'b') {
   for (int i = 0; i < ct[2]; i++) {
    cout << 'c';
   }
   for (int i = 0; i < ct[1]; i++) {
    cout << 'b';
   }
  } else {
   for (int i = 0; i < ct[1]; i++) {
    cout << 'b';
   }
   for (int i = 0; i < ct[2]; i++) {
    cout << 'c';
   }
  }
  sort(rem.begin(), rem.end());
  cout << rem << '\n';
 }
}