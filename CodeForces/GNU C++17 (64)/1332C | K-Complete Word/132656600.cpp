#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, k;
  string S;
  cin >> n >> k >> S;
  vector<vector<int>> count(k, vector<int>(26));
  for (int i = 0; i < n; i += k) {
   string s = S.substr(i, k);
   for (int j = 0; j < (k + 1) / 2; j++) {
    count[j][s[j] - 'a']++;
    if (j != k - j - 1) {
     count[j][s[k - j - 1] - 'a']++;
    }
   } 
  }
  int ans = 0;
  for (auto x : count) {
   ans += accumulate(x.begin(), x.end(), 0) - *max_element(x.begin(), x.end());
  }
  cout << ans << '\n';
 }
}