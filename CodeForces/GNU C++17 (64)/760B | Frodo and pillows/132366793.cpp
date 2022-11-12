#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 ll n, m, k;
 cin >> n >> m >> k;
 k--;
 m -= n;
 auto check = [&](int x) {
  ll sum = x;
  int add = x - 1, idx = 1;
  while (k - idx >= 0 && add > 0) {
   sum += add;
   add--;
   idx++;
  }
  add = x - 1, idx = 1;
  while (k + idx < n && add > 0) {
   sum += add;
   add--;
   idx++;
  }
  return sum <= m;
 };
 int l = 0, r = m + 1;
 while (l + 1 < r) {
  int mid = l + (r - l) / 2;
  if (check(mid)) {
   l = mid;
  } else {
   r = mid;
  }
 }
 cout << l + 1 << '\n';
}