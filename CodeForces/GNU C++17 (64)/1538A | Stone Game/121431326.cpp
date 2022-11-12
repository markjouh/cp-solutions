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
  vector<int> v(n);
  int mn = 2e9, minpos;
  int mx = 0, maxpos;
  for (int i = 0; i < n; i++) {
   cin >> v[i];
   if (v[i] < mn) {
    mn = v[i];
    minpos = i;
   }
   if (v[i] > mx) {
    mx = v[i];
    maxpos = i;
   }
  }
  if (minpos > maxpos) {
   swap(minpos, maxpos);
  }
  int ans = 2e9;
  ans = min(ans, maxpos + 1); // both on left
  ans = min(ans, n - minpos); // both on right
  ans = min(ans, minpos + n - maxpos + 1); // left and right
  cout << ans << '\n';
 }
}