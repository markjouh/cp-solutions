#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<pair<int, int>> ranges(n);
  for (auto &[f, s] : ranges) {
   cin >> f >> s;
  }
  set<pair<int, int>> st(ranges.begin(), ranges.end());
  for (auto [l, r] : ranges) {
   cout << l << ' ' << r << ' ';
   if (l == r) {
    cout << l << '\n';
   }
   if (st.count({l + 1, r})) {
    cout << l << '\n';
    continue;
   }
   if (st.count({l, r - 1})) {
    cout << r << '\n';
    continue;
   }
   for (int i = l + 1; i <= r - 1; i++) {
    if (st.count({l, i - 1}) && st.count({i + 1, r})) {
     cout << i << '\n';
     break;
    }
   }
  }
  cout << '\n';
 }
}