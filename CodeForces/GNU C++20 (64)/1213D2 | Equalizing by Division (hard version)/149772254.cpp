#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  sort(all(a));
  vector<vector<int>> b(2e5 + 1, vector<int>(2));
  for (int &x : a) {
    int ct = 0;
    while (x > 0) {
      if (b[x][0] < k) {
        b[x][1] += ct;
        b[x][0]++;
      }
      x /= 2;
      ct++;
    }
    if (b[0][0] < k) {
      b[0][1] += ct;
      b[0][0]++;
    }
  }
  int ans = 1e9;
  for (int i = 0; i <= 2e5; i++) {
    if (b[i][0] == k) {
      ans = min(ans, b[i][1]);
    }
  }
  cout << ans << '\n';
}