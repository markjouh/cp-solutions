#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n, k;
 cin >> n >> k;
 ll l = 0, r = 1e12;
 while (l + 1 < r) {
  ll mid = l + (r - l) / 2;
  ll res = 0, reduce = 1;
  while (mid / reduce > 0) {
   res += mid / reduce;
   reduce *= k;
  }
  if (res >= n) {
   r = mid;
  } else {
   l = mid;
  }
 }
 cout << r << '\n';
}