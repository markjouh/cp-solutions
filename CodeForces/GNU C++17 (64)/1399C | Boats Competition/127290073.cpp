#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  vector<set<int>> vals(n * 2 + 1);
  for (int i = 0; i < n; i++) {
   for (int j = i + 1; j < n; j++) {
    int sum = a[i] + a[j];
    if (!vals[sum].count(i) && !vals[sum].count(j)) {
     vals[sum].insert(i);
     vals[sum].insert(j);
    }
   }
  }
  int ans = 0;
  for (auto x : vals) {
   ans = max(ans, (int)x.size());
  }
  ans /= 2;
  cout << ans << '\n';
 }
}