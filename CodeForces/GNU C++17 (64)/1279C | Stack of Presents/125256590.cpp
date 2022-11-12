#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, m;
  cin >> n >> m;
  vector<int> p(n + 1);
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   p[x] = i;
  }
  int last = -1;
  ll ans = m;
  for (int i = 0; i < m; i++) {
   int x;
   cin >> x;
   if (p[x] > last) {
    ans += (p[x] - i) * 2;
    last = p[x];
   }
  }
  cout << ans << '\n';
 }
}