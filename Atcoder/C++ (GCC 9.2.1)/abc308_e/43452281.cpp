#include "bits/stdc++.h"

using namespace std;

#define int long long

int dp[4][2][2][2]; // [Nth character of MEX][has 0][has 1][has 2] = count

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  memset(dp, sizeof(dp), 0);
  dp[0][0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    int idx = string("MEX").find(s[i]) + 1;
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
          dp[idx][j || (a[i] == 0)][k || (a[i] == 1)][l || (a[i] == 2)] += dp[idx - 1][j][k][l];
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        int mex = i + (i & j) + (i & j & k);
        ans += dp[3][i][j][k] * mex;
      }
    }
  }
  cout << ans << '\n';
}
