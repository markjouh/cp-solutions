#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  string s;
  cin >> n >> k >> s;
  int next, idx = s.find('*'), ans = 0;
  while (idx < n) {
   ans++;
   next = n;
   for (int i = 1; i <= k; i++) {
    if (idx + i < n && s[idx + i] == '*') {
     next = idx + i;
    }
   }
   idx = next;
  }
  cout << ans << '\n';
 }
}