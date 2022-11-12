#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int pre[6][200000 + 1];
const string pm[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n, m;
 string s;
 cin >> n >> m >> s;
 for (int i = 0; i < 6; i++) {
  for (int j = 0; j < n; j++) {
   pre[i][j + 1] = pre[i][j] + (s[j] != pm[i][j % 3]);
  }
 }
 while (m--) {
  int l, r;
  cin >> l >> r;
  int res = INT_MAX;
  for (int i = 0; i < 6; i++) {
   res = min(res, pre[i][r] - pre[i][l - 1]);
  }
  cout << res << '\n';
 }
}