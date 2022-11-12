#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  long long a, b;
  cin >> a >> b;
  if (a == b) {
   cout << 0 << ' ' << 0 << '\n';
   continue;
  }
  long long diff = abs(a - b);
  cout << diff << ' ' << min(abs(a - (a + diff - 1) / diff * diff), abs(a - a / diff * diff)) << '\n';
 }
}