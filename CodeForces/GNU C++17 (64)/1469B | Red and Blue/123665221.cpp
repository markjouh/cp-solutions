#include <bits/stdc++.h>
int main() {
 std::cin.sync_with_stdio(0);
 std::cin.tie(0);
 int t;
 std::cin >> t;
 while (t--) {
  int a = 0, b = 0, cnt = 0;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
   int x;
   std::cin >> x;
   cnt += x;
   a = std::max(a, cnt);
  }
  cnt = 0;
  int m;
  std::cin >> m;
  for (int i = 0; i < m; i++) {
   int x;
   std::cin >> x;
   cnt += x;
   b = std::max(b, cnt);
  }
  std::cout << a + b << '\n';
 }
}