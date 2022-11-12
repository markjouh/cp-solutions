#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  ll sum = 0;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   sum += x;
   mp[x]++;
  }
  if ((sum * 2) % n) {
   cout << 0 << '\n';
   continue;
  }
  int target = sum * 2 / n;
  ll ans = 0;
  for (auto [x, y] : mp) {
   if (x * 2 == target) {
    ans += (y - 1) * (ll)y;
   } else {
    ans += y * (ll)mp[target - x];
   }
  }
  ans /= 2;
  cout << ans << '\n';
 }
}