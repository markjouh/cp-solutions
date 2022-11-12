#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int maximilian = 1e6;
int p[maximilian];
 
int L;
 
ll get(ll x) {
  return 1ll * x / L * p[L - 1] + p[x % L];
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    ll a, b, q;
    cin >> a >> b >> q;
    
    L = lcm(a, b);
    for (int i = 0; i < L; i++)
      p[i] = i % a % b != i % b % a;
    for (int i = 1; i < L; i++)
      p[i] += p[i - 1];
 
    while (q--) {
      ll l, r;
      cin >> l >> r;
      cout << get(r) - get(l - 1) << ' ';
    }
    cout << '\n';
  }
}