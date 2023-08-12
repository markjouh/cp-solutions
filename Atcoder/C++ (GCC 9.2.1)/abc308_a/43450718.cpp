#include "bits/stdc++.h"

using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> a(8);
  for (int i = 0; i < 8; i++) {
    cin >> a[i];
  }
  bool ok = true;
  for (int i = 0; i < 8; i++) {
    ok &= a[i] >= 100;
    ok &= a[i] <= 675;
    ok &= a[i] % 25 == 0;
    if (i > 0) {
      ok &= a[i] >= a[i - 1];
    }
  }
  cout << (ok ? "Yes\n" : "No\n");
}
