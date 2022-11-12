#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int solve(string s, int n, int k) {
 vector<int> pre(n + 1);
 for (int i = 0; i < n; ++i) {
  pre[i + 1] = pre[i] + (s[i] == 'b');
 }
 int res = 0;
 for (int i = 0; i < n; ++i) {
  int l = 0, r = n + 1;
  while (l + 1 < r) {
   int mid = l + (r - l) / 2;
   if (pre[mid] - pre[i] <= k) {
    l = mid;
   } else {
    r = mid;
   }
  }
  res = max(res, l - i);
 }
 return res;
}
 
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n, k;
 string s;
 cin >> n >> k >> s;
 int ans = solve(s, n, k);
 string s2;
 for (char c : s) {
  s2 += (c == 'a' ? 'b' : 'a');
 }
 ans = max(ans, solve(s2, n, k));
 cout << ans << '\n';
}