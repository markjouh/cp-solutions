#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  ll a, b, x, y, n;
  cin >> a >> b >> x >> y >> n;
  ll res1 = (a - min(a - x, n)) * (b - min(b - y, (n - min(a - x, n))));
  ll res2 = (b - min(b - y, n)) * (a - min(a - x, (n - min(b - y, n))));
  cout << min(res1, res2) << '\n';
 }
}