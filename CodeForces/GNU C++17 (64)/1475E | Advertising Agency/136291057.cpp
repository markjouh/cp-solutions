#include <bits/stdc++.h>
using namespace std;
 
const int M = 1e9 + 7;
 
long long mpow(long long base, long long exp) {
 long long res = 1;
 while (exp) {
  if (exp % 2 == 1){
   res = (res * base) % M;
  }
  exp >>= 1;
  base = (base * base) % M;
 }
 return res;
}
 
long long minv(long long base) {
 return mpow(base, M - 2);
}
 
const int FSIZE = 1e6;
vector<long long> fact(1e6), ifact(1e6);
void genmfact(long long n) {
 fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
 for (long long i = 2; i <= n; i++) {
  fact[i] = (i * fact[i - 1]) % M;
 }
 ifact[n] = minv(fact[n]);
 for (long long i = n - 1; i >= 2; i--) {
  ifact[i] = ((i + 1) * ifact[i + 1]) % M;
 }
}
 
long long nck(long long n, long long k) {
 long long den = (ifact[k] * ifact[n - k]) % M;
 return (fact[n] * den) % M;
}
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 genmfact(1e6);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int& x : nums) {
   cin >> x;
  }
  sort(nums.begin(), nums.end(), greater<int>());
  vector<int> ct(n);
  for (int i = 0; i < n; ++i) {
   if (i) {
    ct[i] = ct[i - 1];
   }
   ct[i] += nums[i] == nums[k - 1];
  }
  cout << nck(ct[n - 1], ct[k - 1]) % M <<'\n';
 }
}