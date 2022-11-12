#include <bits/stdc++.h>
using namespace std;
 
const int M = 998244353;
 
long long mod_inv(long long a, long long m = M) {
 return a == 1 ? 1 : m - mod_inv(m % a, a) * m / a;
}
 
long long choose(long long n, long long k) {
 long long res = 1;
 for (long long i = 0; i < k; i++) {
  res = res * (n - i) % M * mod_inv(i + 1) % M;
 }
 return res;
}
 
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n, m, k;
 cin >> n >> m >> k;
 long long res = m;
 for (int i = 0; i < k; i++) {
  res = res * (m - 1) % M;
 }
 res = res * choose(n - 1, k) % M;
 cout << res << '\n';
}
 
/*
 Think before implementing!
*/