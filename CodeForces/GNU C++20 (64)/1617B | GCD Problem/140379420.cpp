#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int T;
 cin >> T;
 while (T--) {
  int n;
  cin >> n;
  n--;
  if (n % 2 == 1) {
   cout << n / 2 + n % 2 << ' ' << n / 2 << ' ' << 1 << '\n';
  } else {
   int x = 2;
   while (gcd(x, n - x) != 1) {
    x++;
   }
   cout << x << ' '  << n - x << ' ' << 1 << '\n';
  }
 }
}