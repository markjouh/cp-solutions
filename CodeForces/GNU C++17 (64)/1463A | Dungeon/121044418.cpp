#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  int a, b, c;
  cin >> a >> b >> c;
  if (min({a, b, c}) < (a + b + c) / 9 || (a + b + c) % 9) {
   cout << "NO" << '\n';
  } else {
   cout << "YES" << '\n';
  }
 }
}