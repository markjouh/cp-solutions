#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.tie(0);
 cin.sync_with_stdio(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int a, b;
  cin >> a >> b;
  cout << ((a + b) % 3 == 0 && min(a, b) * 2 >= max(a, b) ? "YES" : "NO") << '\n';
 }
}