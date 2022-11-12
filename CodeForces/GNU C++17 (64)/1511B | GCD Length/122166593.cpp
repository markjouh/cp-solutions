#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int a, b, c;
  cin >> a >> b >> c;
  long long a1 = pow(10, a - 1), c1 = pow(10, c - 1), b1 = 0;
  for (int i = 0; i < b - c + 1; i++) {
   b1 *= 10;
   b1++;
  }
  b1 *= c1;
  cout << a1 << ' ' << b1 << '\n';
 }
}