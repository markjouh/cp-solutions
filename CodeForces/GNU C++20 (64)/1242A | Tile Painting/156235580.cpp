#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define sz(x) int(size(x))
#define all(x) begin(x), end(x)
 
// https://cp-algorithms.com/algebra/factorization.html
vector<long long> trial_division3(long long n) {
    vector<long long> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
 
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  map<ll, int> mp;
  for (ll x : trial_division3(n)) {
    mp[x]++;
  }
  cout << (sz(mp) == 1 ? begin(mp)->first : 1) << '\n';
}