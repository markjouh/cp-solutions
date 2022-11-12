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
  vector<pair<int, int>> vp(n);
  for (int i = 0; i < n; i++) {
   cin >> vp[i].first;
   vp[i].second = i;
  }
  sort(vp.begin(), vp.end());
  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
   if (vp[i].second + 1 != vp[i + 1].second) {
    cnt++;
   }
  }
  cout << (cnt < k ? "YES" : "NO") << '\n';
 }
}