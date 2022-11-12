#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
// cloudcloud
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr); 
 string s;
 cin >> s;
 int n = s.size();
 vector<vector<int>> suf(n + 1, vector<int>(26));
 for (int i = n - 1; i >= 0; --i) {
  suf[i] = suf[i + 1];
  ++suf[i][s[i] - 'a'];
 } 
 vector<vector<ll>> cnt(26, vector<ll>(26));
 for (int i = 0; i < n; ++i) {
  for (int j = 0; j < 26; ++j) {
   cnt[s[i] - 'a'][j] += suf[i + 1][j];
  }
 }
 ll ans = *max_element(suf[0].begin(), suf[0].end());
 for (int i = 0; i < 26; ++i) {
  for (int j = 0; j < 26; ++j) {
   ans = max(ans, cnt[i][j]);
  }
 }
 cout << ans << '\n';
}