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
 
using ll = long long;
#define all(x) begin(x), end(x)
#define sz(x) int(size(x))
 
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
 
const int mxn = 1.5e7 + 1;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  sieve(mxn);
  map<int, int> mnExp, mnExpCnt, facCnt;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (auto [f, s] : factorize(x)) {
      if (!facCnt.count(f) || s < mnExp[f]) {
        mnExp[f] = s;
        mnExpCnt[f] = 0;
      }
      if (s == mnExp[f]) {
        mnExpCnt[f]++;
      }
      facCnt[f]++;
    }
  }
  int ans = 1e9;
  for (auto [f, s] : facCnt) {
    if (s < n) {
      mnExpCnt[f] = n - s;
    }
    if (mnExpCnt[f] != n) {
      ans = min(ans, mnExpCnt[f]);
    }
  }
  cout << (ans == 1e9 ? -1 : ans);
  DEBUG(mnExp);
  DEBUG(mnExpCnt);
}
 
/*
  For each prime factor p that occurs in a, store the minimum exponent of p, the amount of that minimum exponent,
  and the total number of distinct elements in a that contain p.
 
  For each p,
    If every number in a has the same number of p's in their factorizations, there's no way we can increase the number
    of occurrences of p in the gcd. (continue)
 
    If there are numbers in a that don't contain the factor p, the minimum exponent is 0, and the number of occurrences of 0
    is n - the number of distinct elements in a that contain p. We only need to set the mnExpCnt part.
 
    Update ans if if the number of occurences of the minimum exponenent of p is less than the current ans.
 
  This works because
    There is never any reason to try to multiply the gcd by some non prime factor f, since this is the same as increasing the
    occurrences of each factor in its prime factorization.
 
    We can never increase the occurrences of a prime factor p in the gcd if each number in a has the same number of occurrences
    of p, since the minimum will never increase.
 
    If there is more than one distinct number of occurrences of p in the gcd, we can always increase the gcd by removing some
    elements, as taking away all of the numbers in a with minimum occurences of p will increase the new minimum.
 
  The time complexity is O(mxn * log(log(mxn)) + n * log(mxn)^2)
*/