#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  string s, t;
  cin >> s >> t;
  map<char, int> mp;
  for (int i = 0; i < s.size(); ++i) {
   mp[s[i]] = i;
  }
  int pos = mp[t[0]], ans = 0;
  for (int i = 1; i < t.size(); ++i) {
   ans += abs(pos - mp[t[i]]);
   pos = mp[t[i]];
  }
  cout << ans << '\n';
 }
}