// Author: mzh
// Problem: H. Fill The Bag
// Contest: Codeforces - ДЗ 2 (Жадность)
// URL: https://codeforces.com/group/Ap6SQK7app/contest/303638/problem/H
// Memory Limit: 256 MB
// Time Limit: 2000 ms
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define int int64_t
 
const int bits = 60;
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(bits);
    int sum = 0;
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      cnt[__builtin_ctz(x)]++;
      sum += x;
    }
    if (sum < n) {
      cout << -1 << '\n';
      continue;
    }
    int ans = 0;
    for (int i = 0; i < bits; i++) {
      if ((n >> i) & 1) {
        if (cnt[i] > 0) {
          cnt[i]--;
        } else {
          int next = i;
          while (cnt[next] == 0) {
            next++;
          }
          cnt[next]--;
          for (int j = i; j < next; j++) {
            cnt[j]++;
          }
          ans += next - i;
        }
      }
      if (i < bits - 1) {
        cnt[i + 1] += cnt[i] / 2;
      }
    }
    cout << ans << '\n';
  }
}