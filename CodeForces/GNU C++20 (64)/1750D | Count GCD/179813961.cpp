#include <bits/stdc++.h>
using namespace std;
 
// for two elements a[i - 1] and a[i],
// b[i] can be a[i] * x where:
// a[i] * x <= m
// gcd(x, a[i - 1]) = 1
 
// so,
// let k = m / a[i]
// let l = a[i - 1] / a[i] (if not evenly divisible then answer is 0)
// we want to find the number of elements i in [1, k] with gcd(i, l) == 1 (coprime to l)
 
// observations:
// we can only lose a factor around log(m) times (~30)
// how do we find the number of elements [1..n] coprime with l in sqrt(n) time at most?
 
#define int int64_t
 
const int MOD = 998244353;
 
vector<bool> isprime;
vector<int> primes, mnfactor;
 
void sieve(int n) {
  isprime.resize(n + 1);
  fill(isprime.begin(), isprime.end(), 1);
  isprime[0] = isprime[1] = false;
  mnfactor.resize(n + 1);
  // Runs in O(n * log(log(n))).
  for (int i = 2; i <= n; i++) {
    if (isprime[i]) {
      primes.push_back(i);
      mnfactor[i] = i;
      for (int j = i * i; j <= n; j += i) {
        isprime[j] = false;
        mnfactor[j] = i;
      }
    }
  }
}
 
vector<pair<int, int>> factorize(int n) {
  vector<pair<int, int>> res;
  // O(log(n)) if we've run sieve up to n.
  if (n <= int(isprime.size()) - 1) {
    while (n != 1) {
      int f = mnfactor[n];
      int exp = 0;
      while (n % f == 0) {
        n /= f;
        exp++;
      }
      res.push_back({f, exp});
    }
  }
  // O(sqrt(n) / log(n)) otherwise. Sieve must be run until at least sqrt(n).
  for (int p : primes) {
    if (p * p > n) {
      break;
    }
    if (n % p == 0) {
      int exp = 0;
      while (n % p == 0) {
        n /= p;
        exp++;
      }
      res.push_back({p, exp});
    }
  }
  if (n > 1) {
    res.push_back({n, 1});
  }
  return res;
}
 
int coprime(int n, int k) {
  vector<int> fac;
  for (auto [f, s] : factorize(k)) {
    fac.push_back(f);
  }
 
  int m = fac.size(); // m <= 10
  int ans = n;
  for (int i = 1; i < (1 << m); i++) {
    int cnt = 0;
    int prod = 1;
    for (int j = 0; j < m; j++) {
      int b = 1 << j;
      if (i & b) {
        cnt++;
        prod *= fac[j];
      }
    }
    if (cnt % 2) {
      ans -= n / prod;
    } else {
      ans += n / prod;
    }
  }
  return ans % MOD;
}
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve(1e5);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
      if (a[i - 1] % a[i]) {
        ans = 0;
        break;
      }
      int k = m / a[i];
      int l = a[i - 1] / a[i];
      (ans *= coprime(k, l)) %= MOD;
    }
    cout << ans << '\n';
  }
}