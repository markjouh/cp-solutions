#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, a, b;
  cin >> n >> a >> b;
  long long sub = 1;
  bool ok = false;
  while (sub <= n) {
   ok |= (n - sub) % b == 0;
   sub *= a;
   if (a == 1 || ok) {
    break;
   }
  }
  cout << (ok ? "Yes" : "No") << '\n';
 }
}