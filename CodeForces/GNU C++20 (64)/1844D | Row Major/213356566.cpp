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
    vector<int> div;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        div.push_back(i);
        if (i * i != n) {
          div.push_back(n / i);
        }
      }
    }
    sort(div.begin(), div.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      vector<bool> ok(26, true);
      for (int d : div) {
        if (d > i) {
          break;
        }
        ok[ans[i - d]] = false;
      }
      for (int j = 0; j < 26; j++) {
        if (ok[j]) {
          ans[i] = j;
          break;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << char('a' + ans[i]);
    }
    cout << '\n';
  }
}