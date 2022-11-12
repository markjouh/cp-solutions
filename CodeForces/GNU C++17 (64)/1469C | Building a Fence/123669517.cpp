#include <bits/stdc++.h>
int main() {
 std::cin.sync_with_stdio(0);
 std::cin.tie(0);
 int t;
 std::cin >> t;
 while (t--) {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
   std::cin >> a[i];
  }
  int mn = a[0], mx = a[0];
  bool ok = true;
  for (int i = 1; i < n; i++) {
   mn = std::max(mn - k + 1, a[i]);
   mx = std::min(mx + k - 1, a[i] + k - 1);
   if (mn > mx) {
    ok = false;
    break;
   }
  }
  if (a[n - 1] < mn || a[n - 1] > mx) {
   ok = false;
  }
  std::cout << (ok ? "Yes" : "No") << '\n';
 }
}