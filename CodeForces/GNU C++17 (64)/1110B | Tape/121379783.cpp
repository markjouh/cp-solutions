#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int n, m, k;
 cin >> n >> m >> k;
 vector<int> v(n), diff(n - 1);
 for (int i = 0; i < n; i++) {
  cin >> v[i];
  if (i > 0) {
   diff[i - 1] = v[i] - v[i - 1];
  }
 }
 int cnt = n, ans = n;
 sort(diff.begin(), diff.end(), greater<int>());
 while (cnt > k) {
  ans += diff.back() - 1;
  cnt--;
  diff.pop_back();
 }
 cout << ans << '\n';
}