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
  vector<pair<int, int>> caves(n);
  for (int i = 0; i < n; i++) {
   int k;
   cin >> k;
   int mx = 0;
   for (int j = 0; j < k; j++) {
    int x;
    cin >> x;
    mx = max(mx, x - j + 1);
   }
   caves.push_back({mx, k});
  }
  sort(caves.begin(), caves.end());
  ll add = 0, cur = 0;
  for (auto [x, y] : caves) {
   if (cur < x) {
    add += x - cur;
    cur = x;
   }
   cur += y;
  }
  cout << add << '\n';
 }
}