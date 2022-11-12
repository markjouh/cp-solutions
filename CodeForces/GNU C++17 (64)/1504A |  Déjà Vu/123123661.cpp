#include <bits/stdc++.h>
using namespace std;
 
bool palindrome(string s) {
 for (int i = 0; i < s.size() / 2; i++) {
  if (s[i] != s[s.size() - i - 1]) {
   return false;
  }
 }
 return true;
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  string s;
  cin >> s;
  if (s == string(s.size(), 'a')) {
   cout << "NO" << '\n';
   continue;
  }
  cout << "YES" << '\n';
  if (!palindrome('a' + s)) {
   cout << 'a' + s << '\n';
  } else {
   cout << s + 'a' << '\n';
  }
 }
}