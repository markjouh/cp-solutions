#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  int mn = 2e9, mnpos;
  for (int i = 0; i < n; ++i) {
   int x;
   cin >> x;
   if (x < mn) {
    mn = x;
    mnpos = i + 1;
   }
  }
  int a = 1e9 + 7, b = 1e9 + 9;
  cout << n - 1 << '\n';
  for (int i = 1; i <= n; ++i) {
   if (i != mnpos) {
    cout << mnpos << ' ' << i << ' ' << mn << ' ' << (i % 2 ? a : b) << '\n';
   }
  }
 }
}