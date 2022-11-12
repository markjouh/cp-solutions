#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  int mn = 2e9, mx = -2e9;
  for (int i = 0; i < n; i++) {
   int a;
   cin >> a;
   mn = min(mn, a);
   mx = max(mx, a);
  }
  if (mn < 0) {
   cout << "NO" << '\n';
  } else {
   cout << "YES" << '\n' << mx + 1 << '\n';
   for (int i = 0; i <= mx; i++) {
    cout << i << ' ';
   }
   cout << '\n';
  }
 }
}