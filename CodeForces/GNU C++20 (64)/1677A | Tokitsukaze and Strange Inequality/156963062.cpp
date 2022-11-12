#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rep1(i, n) for (int i = 1; i <= int(n); i++)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
      cin >> a[i];
    }
    vector<vector<int>> pre(n + 1, vector<int>(n + 1));
    rep(i, n) {
      pre[i + 1] = pre[i];
      for (int j = a[i]; j <= n; j++) {
        pre[i + 1][j]++;
      }
    }
    long long ans = 0;
    rep(i, n) {
      for (int j = i + 1; j < n; j++) {
        ans += pre[i][a[j]] * (pre[n][a[i]] - pre[j + 1][a[i]]);
      }
    }
    cout << ans << '\n';
  }
}