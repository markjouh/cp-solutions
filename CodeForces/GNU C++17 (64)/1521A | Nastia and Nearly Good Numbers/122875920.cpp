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
  if (b == 1) {
   cout << "NO" << '\n';
   continue;
  }
  cout << "YES" << '\n';
  cout << a << ' ' << a * b << ' ' << a * (b + 1) << '\n';
 }
}