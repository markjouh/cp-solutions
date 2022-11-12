#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i];
      pref[i + 1] += s[i] == 'W';
    }
    int ans = 1e9;
    for (int i = 0; i + k <= n; i++) {
      ans = min(ans, pref[i + k] - pref[i]);
    }
    cout << ans << '\n';
  }
}