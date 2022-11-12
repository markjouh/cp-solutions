#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> v(n);
  for (int &x : v) {
   cin >> x;
  }
  sort(v.begin(), v.end());
  long long ans = 0;
  for (int x : v) {
   ans += upper_bound(v.begin(), v.end(), r - x) - v.begin();
   ans -= lower_bound(v.begin(), v.end(), l - x) - v.begin();
   if (x * 2 >= l && x * 2 <= r) {
    ans--;
   }
  }
  cout << ans / 2 << '\n';
 }
}