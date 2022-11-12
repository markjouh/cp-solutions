#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  string s;
  cin >> s;
  char last = ' ';
  int ans = 0;
  for (char c : s) {
   if (c == '0' && c != last) {
    ans++;
   }
   last = c;
  }
  cout << min(ans, 2) << '\n';
 }
}