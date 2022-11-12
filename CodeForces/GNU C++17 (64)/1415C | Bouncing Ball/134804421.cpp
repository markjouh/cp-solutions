#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
// cloudcloud
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr); 
 int tc;
 cin >> tc;
 while (tc--) {
  int n, p, k, x, y;
  string s;
  cin >> n >> p >> k >> s >> x >> y;
  vector<int> cost(n);
  for (int i = n - 1; i >= 0; --i) {
   cost[i] = (s[i] == '0' ? x : 0);
   if (i + k < n) {
    cost[i] += cost[i + k];
   }
  }
  int ans = 1e9;
  --p; // Make 0-indexed
  for (int i = p; i < n; ++i) {
   ans = min(ans, (i - p) * y + cost[i]);
  }
  cout << ans << '\n';
 }
}