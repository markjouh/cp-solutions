#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  vector<int> ct(26);
  vector<vector<long long>> occur(26, vector<long long>(26));
  for (int i = s.size()-1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      occur[s[i]-'a'][j] += ct[j];
    }
    ct[s[i]-'a']++;
  }
  long long ans = 0;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      ans = max(ans, occur[i][j]);
    }
    ans = max(ans, (long long)ct[i]);
  }
  cout << ans << '\n';
}