#include <bits/stdc++.h>
using namespace std;
 
bool sq(int x) {
 int y = sqrt(x);
 return y * y == x;
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  cout << ((n % 2 == 0 && sq(n / 2)) || (n % 4 == 0 && sq(n / 4)) ? "YES" : "NO") << '\n';
 }
}