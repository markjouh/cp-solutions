#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n, m;
 string s;
 cin >> n >> m >> s;
 vector<vector<int>> pre(6, vector<int>(n + 1));
 string temp = "abc";
 for (int i = 0; i < 6; i++) {
  for (int j = 0; j < n; j++) {
   pre[i][j + 1] = pre[i][j] + (s[j] != temp[j % 3]);
  }
  next_permutation(temp.begin(), temp.end());
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