#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  long long x;
  cin >> x;
  while (x % 2 == 0) {
   x /= 2;
  }
  cout << (x != 1 ? "YES" : "NO") << '\n';
 }
}