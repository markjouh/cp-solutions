#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  cout << n - 1 + m - 1 + n * m - 1 << '\n';
  for (int i = 0; i < n - 1; i++) {
    cout << 'U';
  }
  for (int i = 0; i < m - 1; i++) {
    cout << 'L';
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (i % 2 == 0) {
        cout << 'R';
      } else {
        cout << 'L';
      }
    }
    if (i < n - 1) {
      cout << 'D';
    }
  }
}