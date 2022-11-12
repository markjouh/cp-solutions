#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<vector<bool>> ct;
 for (int i = 0; i < n; ++i) {
  string s;
  cin >> s;
  vector<bool> cur(26);
  for (char c : s) {
   cur[c - 'a'] = cur[c - 'a'] ^ 1;
  }
  ct.push_back(cur);
 }
 unordered_map<vector<bool>, int> mp;
 long long ans = 0;
 for (auto v : ct) {
  ans += mp[v];
  for (int i = 0; i < 26; ++i) {
   vector<bool> cur = v;
   cur[i] = cur[i] ^ 1;
   ans += mp[cur];
  }
  ++mp[v];
 }
 cout << ans << '\n';
}