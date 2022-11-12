#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> cnt(n + 1), pre(n + 1);
  for (int i = 1; i <= n; ++i) {
   int x;
   cin >> x;
   ++cnt[x];
   pre[i] = x + pre[i - 1];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
   for (int j = i + 2; j <= n; ++j) {
    int x = pre[j] - pre[i];
    if (x >= 1 && x <= n) {
     ans += cnt[x];
     cnt[x] = 0;
    }
   }
  }
  cout << ans << '\n';
 }
}