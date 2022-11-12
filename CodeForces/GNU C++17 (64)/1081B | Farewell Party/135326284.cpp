#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> a(n);
 vector<vector<int>> cnt(n);
 for (int i = 0; i < n; ++i) {
  cin >> a[i];
  cnt[a[i]].push_back(i);
 }
 bool ok = true;
 for (int i = 0; i < n; ++i) {
  ok &= cnt[i].size() % (n - i) == 0;
 }
 if (!ok) {
  cout << "Impossible" << '\n';
  return 0;
 }
 cout << "Possible" << '\n';
 int type = 1;
 vector<int> res(n);
 for (int i = 0; i < n; ++i) {
  if (cnt[i].size()) {
   int ct = 0;
   for (int j : cnt[i]) {
    res[j] = type;
    ++ct;
    if (ct == n - i) {
     ct = 0;
     ++type;
    }
   }
  }
 }
 for (int x : res) {
  cout << x << ' ';
 }
 
}