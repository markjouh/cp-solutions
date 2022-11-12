#include <bits/stdc++.h>
using namespace std;
 
int maxdiv(int x) {
 int res = 0;
 for (int i = 2; i * i <= x; i++) {
  while (x % i == 0) {
   x /= i;
   res++;
  }
 }
 if (x > 1) {
  res++;
 }
 return res;
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int a, b, k;
  cin >> a >> b >> k;
  int mn = 2, mx = maxdiv(a) + maxdiv(b);
  if (a == b) {
   mn = 0;
  } else if (a % b == 0 || b % a == 0) {
   mn = 1;
  }
  cout << (k >= mn && k <= mx && !(mn == 0 && k == 1) ? "YES" : "NO") << '\n';
 }
}