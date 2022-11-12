#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int k;
  cin >> k;
  int cnt = 1, r = 0, c = 0;
  while (k > 0) {
   r = 0;
   c = cnt - 1;
   r += min(cnt, k);
   k -= min(cnt, k);
   c -= min(cnt - 1, k);
   k -= min(cnt - 1, k);
   cnt++;
  }
  cout << r << ' ' << c + 1 << '\n';
 }
}