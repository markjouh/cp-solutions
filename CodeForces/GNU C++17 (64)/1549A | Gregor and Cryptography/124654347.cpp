#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.tie(0);
 cin.sync_with_stdio(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int p;
  cin >> p;
  cout << (p % 2 ? 2 : 3) << ' ' << p - 1 << '\n';
 }
}