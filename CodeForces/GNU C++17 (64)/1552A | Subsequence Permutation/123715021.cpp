#include <bits/stdc++.h>
int main() {
 std::cin.sync_with_stdio(0);
 std::cin.tie(0);
 int t;
 std::cin >> t;
 while (t--) {
  int n;
  std::string a, b;
  std::cin >> n >> a;
  int ans = 0;
  b = a;
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
   if (a[i] != b[i]) {
    ans++;
   }
  }
  std::cout << ans << '\n';
 }
}