#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    s += '*';
    bool ok = true;
    int ct = 1;
    for (int i = 1; i < (int)s.size(); i++) {
      if (s[i] != s[i - 1]) {
        ok &= ct == 2 || ct > 2;
        ct = 0;
      }
      ct++;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}