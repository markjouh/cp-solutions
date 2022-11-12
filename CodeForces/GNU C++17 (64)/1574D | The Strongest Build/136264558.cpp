#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<vector<int>> items(n);
 for (int i = 0; i < n; ++i) {
  int c;
  cin >> c;
  for (int j = 0; j < c; ++j) {
   int x;
   cin >> x;
   items[i].push_back(x);
  }
 }
 int m;
 cin >> m;
 vector<vector<int>> ban(m, vector<int>(n));
 for (int i = 0; i < m; ++i) {
  for (int j = 0; j < n; ++j) {
   cin >> ban[i][j];
   --ban[i][j];
  }
 }
 sort(ban.begin(), ban.end());
 
 auto get = [&](vector<int> pos) {
  vector<int> res(n);
  for (int i = 0; i < n; ++i) {
   res[i] = items[i][pos[i]];
  }
  return res;
 };
 auto vsum = [&](vector<int> v) {
  int res = 0;
  for (int x : v) {
   res += x;
  }
  return res;
 };
 
 vector<int> optimal(n);
 for (int i = 0; i < n; ++i) {
  optimal[i] = items[i].size() - 1;
 }
 if (!binary_search(ban.begin(), ban.end(), optimal)) {
  for (int x : optimal) {
   cout << x + 1 << ' ';
  }
  return 0;
 }
 
 int best = 0;
 vector<int> ans;
 for (auto pos : ban) {
  vector<vector<int>> conn = {pos};
  for (int i = 0; i < n; ++i) {
   if (pos[i] > 0) {
    vector<int> cur = pos;
    --cur[i];
    conn.push_back(cur);
   }
  }
  for (auto v : conn) {
   int csum = vsum(get(v));
   if (!binary_search(ban.begin(), ban.end(), v) && csum > best) {
    best = csum;
    ans = v;
   }
  }
 }
 for (int x : ans) {
  cout << x + 1 << ' ';
 }
}