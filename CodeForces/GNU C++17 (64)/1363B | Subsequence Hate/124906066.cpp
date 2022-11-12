#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.tie(0);
 cin.sync_with_stdio(0);
 int tc;
 cin >> tc;
 while (tc--) {
  string s;
  cin >> s;
  auto cnt = [&](string s) {
   int res = 0;
   for (char c : s) {
    if (c == '0') {
     res++;
    }
   }
   return min(res, (int)s.size() - res);
  };
  int ans = INT_MAX;
  for (int i = 0; i < s.size(); i++) {
   ans = min(ans, cnt(s.substr(0, i)) + cnt(s.substr(i, (int)s.size())));
  }
  cout << ans << '\n';
 }
}