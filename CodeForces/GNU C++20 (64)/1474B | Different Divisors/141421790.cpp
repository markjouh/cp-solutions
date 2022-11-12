#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int mxn = 1e6;
  vector<bool> is_prime(mxn+1, true);
  for (long long i = 2; i <= mxn; i++) {
    if (is_prime[i] && i * i <= mxn) {
      for (long long j = i * i; j <= mxn; j += i) {
        is_prime[j] = false;
      }
    }
  }
  vector<int> primes;
  for (int i = 2; i <= mxn; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
  int tc;
  cin >> tc;
  while (tc--) {
    int d;
    cin >> d;
    int a = *lower_bound(primes.begin(), primes.end(), d+1), b = *lower_bound(primes.begin(), primes.end(), a+d);
    cout << a*b << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/