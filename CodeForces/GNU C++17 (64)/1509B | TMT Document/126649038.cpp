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
  string s;
  cin >> n >> s;
  auto solve = [&]() {
   int cnt = 0;
   for (char c : s) {
    cnt += (c == 'T' ? 1 : -1);
    if (cnt < 0) {
     return false;
    }
   }
   if (cnt != n / 3) {
    return false;
   }
   return true;
  };
  bool ok = true;
  ok &= solve();
  reverse(s.begin(), s.end());
  ok &= solve();
  cout << (ok ? "YES" : "NO") << '\n';
 }
}