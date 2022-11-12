#include <bits/stdc++.h>
using namespace std;
 
const int mod = 998244353;
 
// From https://github.com/galencolin/cp-templates/blob/master/templates/modop.cpp
 
using ll = long long;
 
namespace modop {
  ll madd(ll a, ll b) {
    return (a + b) % mod;
  }
  ll msub(ll a, ll b) {
    return (((a - b) % mod) + mod) % mod;
  }
  ll mmul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
  }
  ll mpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
    if (exp % 2 == 1){
      res = (res * base) % mod;
    }
    exp >>= 1;
    base = (base * base) % mod;
    }
    return res;
  }
  ll minv(ll base) {
    return mpow(base, mod - 2);
  }
  ll mdiv(ll a, ll b) {
    return mmul(a, minv(b));
  }
  
  const ll FACTORIAL_SIZE = 1.1e3;
  ll fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
  bool __factorials_generated__ = 0;
  void gen_factorial(ll n) {
    __factorials_generated__ = 1;
    fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
    
    for (ll i = 2; i <= n; i++) {
      fact[i] = (i * fact[i - 1]) % mod;
    }
    ifact[n] = minv(fact[n]);
    for (ll i = n - 1; i >= 2; i--) {
      ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
    }
  }
  ll nck(ll n, ll k) {
    if (!__factorials_generated__) {
      cerr << "Call gen_factorial you dope" << endl;
      exit(1);
    }
    if (k < 0 || n < k) return 0;
    ll den = (ifact[k] * ifact[n - k]) % mod;
    return (den * fact[n]) % mod;
  }
}
 
using namespace modop;
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    // If n is odd, the answer is 0
    if (n % 2) {
      cout << 0 << '\n';
      continue;
    }
    // Otherwise, the answer is (n/2!)^2. This is because there are
    // n/2 odd numbers which we need to pair with even numbers, and n/2 other numbers
    // that we can arrange freely.
    gen_factorial(1e3);
    cout << 1ll * fact[n / 2] * fact[n / 2] % mod << '\n';
  }
}