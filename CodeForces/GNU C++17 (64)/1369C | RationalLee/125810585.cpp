#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, k;
  cin >> n >> k;
  deque<int> a(n), b(k);
  for (int &x : a) {
   cin >> x;
  }
  for (int &x : b) {
   cin >> x;
   x--;
  }
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end());
  ll ans = 0;
  for (int x : b) {
   if (x == 0) {
    ans += a[0] * 2;
    a.pop_front();
   } else {
    break;
   }
  }
  sort(b.begin(), b.end(), greater<int>());
  for (int x : b) {
   if (x != 0) {
    ans += a[0] + a.back();
    a.pop_front();
    for (int i = 0; i < x; i++) {
     a.pop_back();
    }
   } else {
    break;
   }
  }
  cout << ans << '\n';
 }
}