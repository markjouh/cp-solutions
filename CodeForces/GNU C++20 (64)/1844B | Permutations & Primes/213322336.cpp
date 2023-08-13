#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 1 << '\n';
      continue;
    }
    if (n == 2) {
      cout << 1 << ' ' << 2 << '\n';
      continue;
    }
    vector<int> a(n);
    a[0] = 2;
    a[n / 2] = 1;
    a[n - 1] = 3;
    int cur = 4;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        a[i] = cur++;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
}