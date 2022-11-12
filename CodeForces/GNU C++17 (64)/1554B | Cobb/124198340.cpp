#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  long long ans = LLONG_MIN;
  for (int i = max(0, n - 101); i < n; i++) {
   for (int j = i + 1; j < n; j++) {
    ans = max(ans, 1LL * (i + 1) * (j + 1) - 1LL * k * (a[i] | a[j]));
   }
  }
  cout << ans << '\n';
 }
}