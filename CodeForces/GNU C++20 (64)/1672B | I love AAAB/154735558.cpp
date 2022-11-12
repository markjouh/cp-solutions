#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int cnt[2];
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    memset(cnt, 0, sizeof cnt);
    bool ok = true;
    for (char c : s) {
      cnt[c - 'A']++;
      ok &= cnt[0] >= cnt[1];
    }
    cout << (ok && s[0] == 'A' && s.back() == 'B' ? "YES\n" : "NO\n");
  }
}