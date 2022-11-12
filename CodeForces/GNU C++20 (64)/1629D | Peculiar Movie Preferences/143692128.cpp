#include <bits/stdc++.h>
using namespace std;
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<string> a(n);
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]] = i;
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      ok |= a[i].front() == a[i].back();
      string r = a[i];
      reverse(r.begin(), r.end());
      ok |= mp[r] > i;
      if (r.size() == 2) {
        for (char c = 'a'; c <= 'z'; c++) {
          string cr = c + r;
          ok |= mp[cr] > i;
        }
      }
      if (r.size() == 3) {
        r.erase(r.begin());
        ok |= mp[r] > i;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}