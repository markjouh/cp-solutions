 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
// cloudcloud
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr); 
 int tc;
 cin >> tc;
 while (tc--) {
  int n, k;
  cin >> n >> k;
  --k; // Inclusive distance
  vector<int> colors(n);
  for (int& v : colors) {
   cin >> v;
  }
  int ans = 1e9;
  for (int i = 1; i <= 100; ++i) {
   vector<int> paint;
   for (int j = 0; j < n; ++j) {
    if (colors[j] != i) {
     paint.push_back(j);
    }
   }
   int last = -1e9, cur = 0;
   for (int v : paint) {
    if (v - last > k) {
     last = v;
     ++cur;
    }
   }
   ans = min(ans, cur);
  }
  cout << ans << '\n';
 }
}