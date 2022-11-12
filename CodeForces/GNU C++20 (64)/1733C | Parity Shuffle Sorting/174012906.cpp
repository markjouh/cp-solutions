#include <bits/stdc++.h>
using namespace std;
 
const int mxN = 1e5;
int a[mxN];
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  cout << n - 1 << '\n';
  if (n >= 2) {
   cout << 1 << ' ' << n << '\n';
  }
  for (int i = 1; i < n - 1; i++) {
   if (a[0] % 2 == a[i] % 2) {
    cout << i + 1 << ' ' << n << '\n';
   } else {
    cout << 1 << ' ' << i + 1 << '\n';
   }
  }
 }
}