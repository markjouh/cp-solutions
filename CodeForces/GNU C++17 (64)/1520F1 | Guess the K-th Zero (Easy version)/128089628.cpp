#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n, tc;
 cin >> n >> tc;
 while (tc--) {
  int k;
  cin >> k;
  auto check = [&](int mid) {
   cout << '?' << ' ' << 1 << ' ' << mid + 1 << endl;
   int x;
   cin >> x;
   return mid + 1 - x >= k;
  };
  int l = -1, r = n;
  while (l + 1 < r) {
   int mid = l + (r - l) / 2;
   if (check(mid)) {
    r = mid;
   } else {
    l = mid;
   }
  }
  cout << '!' << ' ' << r + 1 << endl;
 }
}