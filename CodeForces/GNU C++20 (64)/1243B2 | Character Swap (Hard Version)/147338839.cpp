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
    string s, t;
    cin >> n >> s >> t;
    int ct[26]{};
    for (char c : s + t) {
      ct[c - 'a']++;
    }
    bool ok = true;
    for (int i = 0; i < 26; i++) {
      ok &= ct[i] % 2 == 0;
    }
    if (!ok) {
      cout << "No\n";
      continue;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
      if (s[i] == t[i]) {
        continue;
      }
      for (int j = i + 1; j < n; j++) {
        if (t[j] == s[i]) {
          swap(s[j], t[j]);
          ans.push_back({j, j});
          break;
        }
      }
      for (int j = i + 1; j < n; j++) {
        if (s[j] == s[i]) {
          swap(s[j], t[i]);
          ans.push_back({j, i});
          break;
        }
      }
    }
    cout << "Yes\n" << ans.size() << '\n';
    for (auto [f, s] : ans) {
      cout << f + 1 << ' ' << s + 1 << '\n';
    }
  }
}