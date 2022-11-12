#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    string s, t;
    cin >> s >> t;
    reverse(all(t));
    bool skip = false;
    for (int i = (sz(s) + sz(t)) % 2; i < sz(s) && sz(t); i++) {
      if (skip) {
        skip = false;
      } else if (s[i] == t.back()) {
        t.pop_back();
      } else {
        skip = true;
      }
    }
    cout << (t.empty() ? "YES\n" : "NO\n");
  }
}