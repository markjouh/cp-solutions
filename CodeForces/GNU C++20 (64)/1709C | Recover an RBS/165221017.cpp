#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    int n = sz(s);
    if (count(all(s), '?') == 0) {
      cout << "YES\n";
      continue;
    }
    // Need n/2 opening, n/2 closing
    int op = count(all(s), '(');
    int req_op = n / 2 - op;
    for (int i = 0, cnt = 0; i < n; i++) {
      if (s[i] == '?') {
        if (cnt < req_op) {
          if (cnt == req_op - 1) {
            s[i] = ')';
          } else {
            s[i] = '(';
          }
        } else {
          if (cnt == req_op) {
            s[i] = '(';
          } else {
            s[i] = ')';
          }
        }
        cnt++;
      }
    }
    bool ok = true;
    int bal = 0;
    for (int i = 0; i < n; i++) {
      bal += (s[i] == '(' ? 1 : -1);
      ok &= bal >= 0;
    }
    cout << (ok && bal == 0 ? "NO\n" : "YES\n");
    cerr << s << '\n';
  }
}