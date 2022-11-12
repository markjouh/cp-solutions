#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 vector<int> a(n);
 for (int &x : a) {
  cin >> x;
 }
 map<int, int> sums;
 map<int, set<int>> used;
 for (int i = 0; i < n; i++) {
  for (int j = i + 1; j < n; j++) {
   int x = a[i] + a[j];
   if (!used[x].count(i) && !used[x].count(j)) {
    sums[x]++;
    used[x].insert(i);
    used[x].insert(j);
   }
  }
 }
 int ans = 0;
 for (auto [x, y] : sums) {
  ans = max(ans, y);
 }
 cout << ans << '\n';
}