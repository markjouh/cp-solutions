#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    s += '*';
    vector<pair<char, int>> seg;
    int len = 1;
    for (int i = 1; i <= n; i++) {
      if (s[i] != s[i - 1]) {
        seg.push_back({s[i - 1], len});
        len = 0;
      }
      len++;
    }
    reverse(seg.begin(), seg.end()); // back is the closest
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (seg.back().first == t[i]) {
        if (--seg.back().second == 0) {
          seg.pop_back();
        }
        continue;
      }
      if (seg.size() == 1 || !((seg.back().first == 'a' && t[i] == 'b') || (seg.back().first == 'b' && t[i] == 'c'))) {
        ok = false;
        break;
      }
      if (seg[seg.size() - 2].first != t[i]) {
        ok = false;
        break;
      }
      if (--seg[seg.size() - 2].second == 0) {
        seg.erase(seg.begin() + seg.size() - 2);
        if (seg.size() >= 2 && seg.back().first == seg[seg.size() - 2].first) {
          seg[seg.size() - 2].second += seg.back().second;
          seg.pop_back();
        }
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}