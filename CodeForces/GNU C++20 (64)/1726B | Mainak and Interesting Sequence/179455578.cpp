#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if (m < n) {
      cout << "No\n";
      continue;
    }
    if (n % 2) {
      cout << "Yes\n";
      for (int i = 0; i < n - 1; i++) {
        cout << 1 << ' ';
      }
      cout << m - n + 1 << '\n';
    } else {
      if (m % 2) {
        cout << "No\n";
        continue;
      }
      cout << "Yes\n";
      for (int i = 0; i < n - 2; i++) {
        cout << 1 << ' ';
      }
      int h = (m - n + 2) / 2;
      cout << h << ' ' << h << '\n';
    }
  }
}