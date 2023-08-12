// Problem: C - Reversible
// Contest: AtCoder - freee Programming Contest 2023（AtCoder Beginner Contest 310）
// URL: https://atcoder.jp/contests/abc310/tasks/abc310_c
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
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    string r = s[i];
    reverse(r.begin(), r.end());
    if (s[i] > r) {
      s[i] = r;
    }
  }
  sort(s.begin(), s.end());
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      cnt++;
    }
  }
  cout << cnt << '\n';
}
