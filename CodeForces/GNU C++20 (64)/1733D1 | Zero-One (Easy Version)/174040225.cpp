#include <bits/stdc++.h>
using namespace std;
 
constexpr int mxN = 3000;
char a[mxN];
int diff[mxN];
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  long long n, x, y;
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  int pt = 0;
  for (int i = 0; i < n; i++) {
   char c;
   cin >> c;
   if (a[i] != c) {
    diff[pt++] = i;
   }
  }
  if (pt % 2) {
   cout << -1 << '\n';
   continue;
  }
  if (pt == 2) {
   if (n == 2) {
    cout << x << '\n';
   } else if (diff[0] + 1 == diff[1]) {
    cout << min(x, 2 * y) << '\n';
   } else {
    cout << y << '\n';
   }
  } else {
   cout << pt / 2 * y << '\n';
  }
 }
}