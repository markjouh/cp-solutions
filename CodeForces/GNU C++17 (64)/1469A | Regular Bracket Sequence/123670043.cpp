#include <bits/stdc++.h>
int main() {
 std::cin.sync_with_stdio(0);
 std::cin.tie(0);
 int t;
 std::cin >> t;
 while (t--) {
  std::string s;
  std::cin >> s;
  bool case1 = s.find('(') < s.find(')');
  bool case2 = s.find('?') < s.find(')') && s.rfind('?') > s.find('(');
  std::cout << ((case1 || case2) && s.size() % 2 == 0 ? "Yes" : "No") << '\n';
 }
}