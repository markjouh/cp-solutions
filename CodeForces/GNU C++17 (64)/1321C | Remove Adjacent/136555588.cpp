#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 string s;
 cin >> n >> s;
 int ans = 0;
 for (char c = 'z'; c >= 'b'; --c) {
  bool go = true;
  while (go) {
   go = false;
   for (int i = 0; i < s.size(); ++i) {
    if (s[i] == c && (i > 0 && s[i - 1] == c - 1 || i < s.size() - 1 && s[i + 1] == c - 1)) {
     s.erase(s.begin() + i);
     ++ans;
     go = true;
    }
   }
  }
 }
 cout << ans << '\n';
}