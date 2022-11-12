#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    // make sure that all numbers that need to become 0 become 0
    int sub = 0;
    for (int i = 0; i < n; i++) {
      if (b[i] == 0) {
        sub = max(sub, a[i]);
      }
    }
    for (int i = 0; i < n; i++) {
      a[i] -= sub;
      a[i] = max(a[i], 0);
    }
    bool pos = true;
    set<int> d;
    for (int i = 0; i < n; i++) {
      if (b[i] != 0) {
        d.insert(a[i] - b[i]);
        pos &= a[i] - b[i] >= 0;
      }
    }
    cout << (d.size() <= 1 && pos ? "YES\n" : "NO\n");
  }
}