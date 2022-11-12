#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
   ans = max(ans, 1LL * a[i] * a[i + 1]);
  }
  cout << ans << '\n';
 }
}