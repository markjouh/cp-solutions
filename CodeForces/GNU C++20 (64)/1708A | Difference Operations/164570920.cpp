#include <bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool ok = true;
    for (int i = 1; i < n; i++) {
      ok &= a[i] % a[0] == 0;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}