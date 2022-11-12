#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, v, h;
  cin >> n >> v >> h;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  int ans = h + min(h, v);
  for (int i = 1; i < n; i++) {
   int diff = abs(a[i] - a[i - 1]);
   if (diff > 1) {
    ans = 0;
    break;
   }
   if (diff == 1) {
    ans = min(ans, min(h, v));
   }
  }
  cout << ans << '\n';
 }
}