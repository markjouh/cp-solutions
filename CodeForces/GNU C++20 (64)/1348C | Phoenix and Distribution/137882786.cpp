#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
 int n, k;
 string s;
 cin >> n >> k >> s;
 sort(s.begin(), s.end());
 if (s[0] != s[k - 1]) {
  cout << s[k - 1] << '\n';
  continue;
 }
 int ct = 0;
 for (int i = k; i < n; ++i) {
  ct += s[i] == s[k];
 }
 string res;
 if (ct == n - k) {
  res = s[0] + string((ct + k - 1) / k, s[k]);
 } else {
  res = s[0];
  for (int i = k; i < n; ++i) {
   res += s[i];
  }
 }
 cout << res << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Try to think of ideas from past problems
  Check for edge cases, overflow, etc.
*/