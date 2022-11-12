#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  long long a, b, n, m;
  cin >> a >> b >> n >> m;
  if (a == b) {
   if (m) {
    a--;
    m--;
   } else {
    b--;
    n--;
   }
  }
  (a < b ? a : b) -= m;
  cout << (a >= 0 && b >= 0 && a + b >= n ? "Yes" : "No") << '\n';
 }
}