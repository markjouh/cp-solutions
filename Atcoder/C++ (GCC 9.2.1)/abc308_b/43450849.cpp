#include "bits/stdc++.h"

using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<array<int, 3>> p(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    p[i] = {a, a + b, i};
  }
  sort(p.begin(), p.end(), [](array<int, 3> a, array<int, 3> b) {
    if (a[0] * b[1] != b[0] * a[1]) {
      return a[0] * b[1] > b[0] * a[1];
    }
    return a[2] < b[2];
  });
  for (int i = 0; i < n; i++) {
    cout << p[i][2] + 1 << ' ';
  }
  cout << '\n';
}
