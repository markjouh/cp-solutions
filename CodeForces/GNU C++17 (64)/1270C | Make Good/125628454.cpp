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
  ll sum = 0;
  int xr = 0;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   sum += x;
   xr ^= x;
  }
  cout << 2 << '\n' << xr << ' ' << sum + xr << '\n';
 }
}