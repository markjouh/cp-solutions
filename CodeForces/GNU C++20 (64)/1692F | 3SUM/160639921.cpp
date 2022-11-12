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
    vector<int> cnt(10);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x % 10]++;
    }
    vector<int> a;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < min(3, cnt[i]); j++) {
        a.push_back(i);
      }
    }
    int m = a.size();
    bool ok = false;
    for (int i = 0; i < m; i++) {
      for (int j = i + 1; j < m; j++) {
        for (int k = j + 1; k < m; k++) {
          if ((a[i] + a[j] + a[k]) % 10 == 3) {
            ok = true;
            goto out;
          }
        }
      }
    }
    out:;
    cout << (ok ? "YES\n" : "NO\n");
  }
}