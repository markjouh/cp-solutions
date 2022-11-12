#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &x : v) cin >> x;
  sort(v.begin(), v.end(), greater<int>());
  map<int, int> res;
  map<int, set<int>> used;
  for (int i = 0; i < n; i++) {
   for (int j = i + 1; j < n; j++) {
    int sum = v[j] + v[i];
    if (used[sum].count(i) || used[sum].count(j)) continue;
    res[sum]++;
    used[sum].insert(i);
    used[sum].insert(j);
   }
  }
  int ans = 0;
  for (auto x : res) ans = max(ans, x.second);
  cout << ans << '\n';
 }
}