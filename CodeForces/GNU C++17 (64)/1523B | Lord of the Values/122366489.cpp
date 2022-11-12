#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
   cin >> a;
  }
  cout << n * 3 << '\n';
  for (int i = 0; i < n; i += 2) {
   cout << 1 << ' ' << i + 1 << ' ' <<  i + 2 << '\n';
   cout << 2 << ' ' << i + 1 << ' ' <<  i + 2 << '\n';
   cout << 1 << ' ' << i + 1 << ' ' <<  i + 2 << '\n';
   cout << 2 << ' ' << i + 1 << ' ' <<  i + 2 << '\n';
   cout << 1 << ' ' << i + 1 << ' ' <<  i + 2 << '\n';
   cout << 2 << ' ' << i + 1 << ' ' <<  i + 2 << '\n';
  }
 }
}