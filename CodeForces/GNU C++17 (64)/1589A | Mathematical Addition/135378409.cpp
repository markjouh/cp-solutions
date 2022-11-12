#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  ll a, b;
  cin >> a >> b;
  cout << -(a * a) << ' ' << b * b << '\n';
 }
}