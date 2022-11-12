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
  cin >> n;
  vector<int> a(n + 3);
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   a[x]++;
  }
  auto calc = [&](int x, int mult, int div) {
   ll y = 1;
   for (int i = 0; i < mult; i++) {
    y *= x - i;
   }
   return y / div;
  };
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
   // 1 value
   ans += calc(a[i], 3, 6);
   // 2 values, with a[i] requiring 2
   ans += calc(a[i], 2, 2) * a[i + 1];
   ans += calc(a[i], 2, 2) * a[i + 2];
   // 2 values, with a[i] requiring 1
   ans += calc(a[i + 1], 2, 2) * a[i];
   ans += calc(a[i + 2], 2, 2) * a[i];
   // 3 values
   ans += a[i] * a[i + 1] * a[i + 2];
  }
  cout << ans << '\n';
 }
}