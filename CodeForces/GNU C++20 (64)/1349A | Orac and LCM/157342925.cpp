#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rep1(i, n) for (int i = 1; i <= int(n); i++)
 
// https://github.com/nealwu/competitive-programming/blob/master/number_theory/sieve_factor.cc
 
vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
 
void sieve(int maximum) {
  maximum = max(maximum, 1);
  smallest_factor.assign(maximum + 1, 0);
  prime.assign(maximum + 1, true);
  prime[0] = prime[1] = false;
  primes = {};
 
  for (int p = 2; p <= maximum; p++)
    if (prime[p]) {
      smallest_factor[p] = p;
      primes.push_back(p);
 
      for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
        if (prime[i]) {
          prime[i] = false;
          smallest_factor[i] = p;
        }
    }
}
 
// Prime factorizes n in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(log n) time.
vector<pair<int64_t, int>> prime_factorize(int64_t n) {
  int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
  assert(1 <= n && n <= sieve_max * sieve_max);
  vector<pair<int64_t, int>> result;
 
  if (n <= sieve_max) {
    while (n != 1) {
      int64_t p = smallest_factor[n];
      int exponent = 0;
 
      do {
        n /= p;
        exponent++;
      } while (n % p == 0);
 
      result.emplace_back(p, exponent);
    }
 
    return result;
  }
 
  for (int64_t p : primes) {
    if (p * p > n)
      break;
 
    if (n % p == 0) {
      result.emplace_back(p, 0);
 
      do {
        n /= p;
        result.back().second++;
      } while (n % p == 0);
    }
  }
 
  if (n > 1)
    result.emplace_back(n, 1);
 
  return result;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  sieve(2e5);
  map<int, vector<int>> occur;
  rep(i, n) {
    int x;
    cin >> x;
    for (auto [f, s] : prime_factorize(x)) {
      occur[f].push_back(s);
    }
  }
  ll ans = 1;
  for (auto [f, s] : occur) {
    int sz = s.size();
    if (sz == n) {
      int mn = 1e9, smn = 1e9;
      for (int x : s) {
        smn = min(smn, x);
        if (mn > smn) {
          swap(mn, smn);
        }
      }
      ans *= pow(f, smn);
    } else if (sz == n - 1) {
      ans *= pow(f, *min_element(s.begin(), s.end()));
    }
  }
  cout << ans << '\n';
}