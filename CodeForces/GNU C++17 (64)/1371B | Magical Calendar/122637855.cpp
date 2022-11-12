#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  long long n, r;
  cin >> n >> r;
  long long ans = 0;
  ans += min(n - 1, r) * (min(n - 1, r) + 1) / 2;
  if (r >= n) {
   ans++;
  }
  cout << ans << '\n';
 }
}