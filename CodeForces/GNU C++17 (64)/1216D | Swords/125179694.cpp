#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> a(n);
 int pos = 0;
 for (int i = 0; i < n; i++) {
  cin >> a[i];
  if (a[i] > a[pos]) {
   pos = i;
  }
 }
 int div = -1;
 for (int i = 0; i < n; i++) {
  int cur = a[pos] - a[i];
  if (div == -1) {
   div = cur;
  } else {
   div = gcd(div, cur);
  }
 }
 ll res = (1ll * n * a[pos] - accumulate(a.begin(), a.end(), 0ll)) / div;
 cout << res << ' ' << div << '\n';
}