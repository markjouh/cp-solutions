#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 ll n, m; cin >> n >> m;
 vector<ll> ct(m);
 for (int i = 0; i < m; i++) {
  ct[i] += n / m;
 }
 n %= m;
 for (int i = 1; i <= n; i++) {
  ct[i % m]++;
 }
 ll ans = 0;
 for (int i = 0; i < m; i++) {
  for (int j = 0; j < m; j++) {
   if ((i * i + j * j) % m == 0) {
    ans += ct[i] * ct[j];
   }
  }
 } 
 cout << ans << '\n';
}