#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  string s;
  cin >> n >> s;
  string res = s;
  for (int i = 0; i < n; i++) {
   if (s[i] == 'U') {
    res[i] = 'D';
   } else if (s[i] == 'D') {
    res[i] = 'U';
   } else {
    res[i] = s[i];
   }
  }
  cout << res << '\n';
 }
}