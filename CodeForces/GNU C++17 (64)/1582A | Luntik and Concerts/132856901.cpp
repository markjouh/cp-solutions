#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  ll a, b, c;
  cin >> a >> b >> c;
  cout << (a + b * 2 + c * 3) % 2 << '\n';
 }
}