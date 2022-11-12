#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
   int a;
   cin >> a;
   sum += a;
  }
  if (sum == n) {
   cout << 0 << '\n';
  } else if (sum > n) {
   cout << sum - n << '\n';
  } else {
   cout << 1 << '\n';
  }
 }
}