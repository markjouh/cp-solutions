#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
// max change = r - 1
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;  
 while (tc--) {
  ll lo, hi, m;
  cin >> lo >> hi >> m;
  ll a, change = LLONG_MAX;
  for (int i = lo; i <= hi; i++) {
   ll floor = m - m / i * i, ceil = m - (m + i - 1) / i * i;
   if (i <= m && abs(floor) < abs(change)) {
    change = floor;
    a = i;
   }
   if (abs(ceil) < abs(change)) {
    change = ceil;
    a = i;
   }
  }
  
  ll b = lo, c = lo;
  if (change < 0) {
   c -= change;
  }
  if (change > 0) {
   b += change;
  }
  cout << a << ' ' << b << ' ' << c << '\n';
 }
}