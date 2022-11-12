#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> a(n), cntl(n), cntr(n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
   a[i]--;
   if (i < l) {
    cntl[a[i]]++;
   } else {
    cntr[a[i]]++;
   }
  }
  int matchl = 0, matchr = 0;
  for (int i = 0; i < n; i++) {
   int sb = min(cntl[i], cntr[i]);
   cntl[i] -= sb;
   cntr[i] -= sb;
   l -= sb;
   r -= sb;
   matchl += cntl[i] / 2;
   matchr += cntr[i] / 2;
  }
  cout << (l + r) / 2 + max({0, (l - r) / 2 - matchl, (r - l) / 2 - matchr}) << '\n';
 }
}