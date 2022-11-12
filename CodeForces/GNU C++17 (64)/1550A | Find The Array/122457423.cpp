#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  int sum = 0, add = 1, ans = 0;
  while (sum < n) {
   sum += add;
   add += 2;
   ans++;
  }
  cout << ans << '\n';
 }
}