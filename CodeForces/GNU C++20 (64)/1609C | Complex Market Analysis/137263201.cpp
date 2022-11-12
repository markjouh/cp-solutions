#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully
 
bool prime(int x) {
 if (x == 1) {
  return false;
 }
 for (int i = 2; i * i <= x; ++i) {
  if (x % i == 0) {
   return false;
  }
 }
 return true;
}
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, e;
  cin >> n >> e;
  unordered_set<int> ones, primes;
  for (int i = 0; i < n; ++i) {
   int x;
   cin >> x;
   if (x == 1) {
    ones.insert(i);
   } else if (prime(x)) {
    primes.insert(i);
   }
  }
  long long ans = 0;
  for (int x : primes) {
   int lct = 0, rct = 0;
   int l = x - e, r = x + e;
   while (l >= 0 && ones.count(l)) {
    ++lct;
    l -= e;
   }
   while (r < n && ones.count(r)) {
    ++rct;
    r += e;
   }
   ans += lct + rct;
   ans += 1ll * lct * rct;
  }
  cout << ans << '\n';
 }
}