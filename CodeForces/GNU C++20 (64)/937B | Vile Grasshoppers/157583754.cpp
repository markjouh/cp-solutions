#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...)
#endif
 
template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | ";debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}
 
vector<bool> isprime;
vector<int> primes, mnfactor;
 
void sieve(int n) {
  isprime.resize(n + 1);;
  fill(isprime.begin(), isprime.end(), 1);
  isprime[0] = isprime[1] = false;
  mnfactor.resize(n + 1);
  // Runs in O(n * log(log(n))).
  for (long long i = 2; i <= n; i++) {
    if (isprime[i]) {
      primes.push_back(i);
      mnfactor[i] = i;
      for (long long j = i * i; j <= n; j += i) {
        isprime[j] = false;
        mnfactor[j] = i;
      }
    }
  }
}
 
vector<pair<long long, int>> factorize(long long n) {
  vector<pair<long long, int>> res;
  // O(log(n)) if we've run sieve up to n.
  if (n <= (int)isprime.size() - 1) {
    while (n != 1) {
      long long f = mnfactor[n];
      int exp = 0;
      while (n % f == 0) {
        n /= f;
        exp++;
      }
      res.push_back({f, exp});
    }
  }
  // O(sqrt(n) / log(n)) otherwise. Sieve must be run until at least sqrt(n).
  for (long long p : primes) {
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
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int p, y;
  cin >> p >> y;
  sieve(1e5);
  for (int i = y; i > p; i--) {
    auto fac = factorize(i);
    if (fac[0].first > p) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  DEBUG(primes);
}