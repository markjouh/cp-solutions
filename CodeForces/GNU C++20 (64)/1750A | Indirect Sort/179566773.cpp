#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (a[i] <= a[k] && a[j] > a[k]) {
            swap(a[j], a[k]);
          }
        }
      }
    }
    bool ok = true;
    for (int i = 1; i < n; i++) {
      ok &= a[i] >= a[i - 1];
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}