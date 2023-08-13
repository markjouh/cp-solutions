#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
 
const int MOD = 998244353;
 
int mpow(int base, int exp) {
  int res = 1;
  while (exp) {
    if (exp & 1) {
      res = (res * base) % MOD;
    }
    exp >>= 1;
    base = (base * base) % MOD;
  }
  return res;
}
 
vector<int> fact, ifact;
 
int minv(int base) {
  return mpow(base, MOD - 2);
}
 
void genfact(int n) {
  fact.resize(n + 1);
  ifact.resize(n + 1);
  fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
  for (int i = 2; i <= n; i++) {
    fact[i] = (i * fact[i - 1]) % MOD;
  }
  ifact[n] = minv(fact[n]);
  for (int i = n - 1; i >= 2; i--) {
    ifact[i] = ((i + 1) * ifact[i + 1]) % MOD;
  }
}
 
int nck(int n, int k) {
  if (k < 0 || n < k) {
    return 0;
  }
  return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  genfact(5e5);
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + nck(n / i - 1, k - 1)) % MOD;
  }
  cout << ans << '\n';
}