#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int d, v, l, r;
  cin >> d >> v >> l >> r;
  cout << d / v + (l - 1) / v - r / v << '\n';
 }
}