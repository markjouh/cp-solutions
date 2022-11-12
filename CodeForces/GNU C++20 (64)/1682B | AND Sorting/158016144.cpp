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
    vector<int> p(n);
    for (int &x : p) {
      cin >> x;
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (i != p[i]) {
        ans &= p[i];
      }
    }
    cout << ans << '\n';
  }
}