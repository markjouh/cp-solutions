// Problem: A - Order Something Else
// Contest: AtCoder - freee Programming Contest 2023（AtCoder Beginner Contest 310）
// URL: https://atcoder.jp/contests/abc310/tasks/abc310_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"

using namespace std;

#define int long long

// I'm late :blobsweat:

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, p, q;
  cin >> n >> p >> q;
  int mn = 1e9;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mn = min(mn, x);
  }
  cout << min(p, mn + q) << '\n';
}
