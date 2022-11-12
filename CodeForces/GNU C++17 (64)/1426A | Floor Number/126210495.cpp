#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, x;
  cin >> n >> x;
  int floor = 0, ans = 0;
  while (floor < n) {
   if (floor == 0) {
    floor += 2;
   } else {
    floor += x;
   }
   ans++;
  }
  cout << ans << '\n';
 }
}