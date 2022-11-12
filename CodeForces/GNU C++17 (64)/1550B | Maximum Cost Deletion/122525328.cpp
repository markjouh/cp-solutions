#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  int ans = a * n;
  if (b < 0) {
   int cnt = 1;
   for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
     cnt++;
    }
   }
   ans += (cnt / 2 + 1) * b;
  } else {
   ans += b * n;
  }
  cout << ans << '\n';
 }
}