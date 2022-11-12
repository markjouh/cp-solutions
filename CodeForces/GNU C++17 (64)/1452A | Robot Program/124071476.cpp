#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int x, y;
  cin >> x >> y;
  cout << max(x, y) * 2 - (x != y) << '\n';
 }
}