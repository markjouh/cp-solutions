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
  int ans = 0;
  for (int i = 0; i < n; i++) {
   if (s[i] != '0') {
    if (i < n - 1) {
     ans++;
    }
    ans += s[i] - '0';
   }
  }
  cout << ans << '\n';
 }
}