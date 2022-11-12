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
  for (int i = 0; i < n; i++) {
   if (i > 0) {
    ans = max(ans, (long long)a[i] * a[i - 1]);
   }
   if (i < n - 1) {
    ans = max(ans, (long long)a[i] * a[i + 1]);
   }
  }
  cout << ans << '\n';
 }
}