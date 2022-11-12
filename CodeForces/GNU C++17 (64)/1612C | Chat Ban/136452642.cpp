#include <bits/stdc++.h>
using namespace std;
 
long long emotes(long long a, long long k) {
 long long res = 0;
 if (a > k) {
  res += k * (k + 1) / 2;
  a -= k;
  res += a * (k - 1 + k - a) / 2;
 } else {
  res = a * (a + 1) / 2;
 }
 return res;
}
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  long long k, x;
  cin >> k >> x;
  long long l = 0, r = k * 2;
  while (l + 1 < r) {
   long long mid = l + (r - l) / 2;
   if (emotes(mid, k) <= x) {
    l = mid;
   } else {
    r = mid;
   }
  }
  if (x - emotes(l, k) > 0 && l < 2 * k - 1) {
   ++l;
  }
  cout << l << '\n';
 }
}