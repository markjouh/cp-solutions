// Problem: B - Strictly Superior
// Contest: AtCoder - freee Programming Contest 2023（AtCoder Beginner Contest 310）
// URL: https://atcoder.jp/contests/abc310/tasks/abc310_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"

using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  vector<vector<bool>> has(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    int c;
    cin >> c;
    for (int j = 0; j < c; j++) {
      int x;
      cin >> x;
      x--;
      has[i][x] = true;
    }
  }
  bool ok = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (p[i] > p[j]) {
        continue;
      }
      bool all = true, extra = false;
      for (int k = 0; k < m; k++) {
        if (has[j][k]) {
          all &= has[i][k];
        }
        if (!has[j][k]) {
          extra |= has[i][k];
        }
      }
      if ((p[i] < p[j] && all) || (all && extra)) {
        ok = true;
      }
    }
  }
  cout << (ok ? "Yes\n" : "No\n");
}
