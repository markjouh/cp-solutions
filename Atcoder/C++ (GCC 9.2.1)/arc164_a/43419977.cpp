#include "bits/stdc++.h"

using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> pw(38);
  pw[0] = 1;
  for (int i = 0; i < 37; i++) {
    pw[i + 1] = pw[i] * 3;
  }
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 37; i >= 0; i--) {
      while (n >= pw[i]) {
        n -= pw[i];
        cnt++;
      }
    }
    cout << (cnt <= k && (cnt % 2 == k % 2) ? "Yes\n" : "No\n");
  }
}
