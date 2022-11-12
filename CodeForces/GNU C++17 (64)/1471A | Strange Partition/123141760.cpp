#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, x;
  cin >> n >> x;
  int a[n];
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  long long sum = 0, mn = 0, mx = 0;
  for (int i = 0; i < n; i++) {
   mx += (a[i] + x - 1) / x;
   sum += a[i];
  }
  mn = (sum + x - 1) / x;
  cout << mn << ' ' << mx << '\n';
 }
}