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
  vector<int> a(n), b(n);
  int min_a = INT_MAX, min_b = INT_MAX;
  for (int &x : a) {
   cin >> x;
   min_a = min(min_a, x);
  }
  for (int &x : b) {
   cin >> x;
   min_b = min(min_b, x);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
   a[i] -= min_a;
   b[i] -= min_b;
   ans += max(a[i], b[i]);
  }
  cout << ans << '\n';
 }
}