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
    int n;
    cin >> n;
    vector<string> a(n);
    unordered_set<string> st;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      st.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
      bool ok = false;
      for (int j = 0; j + 1 < sz(a[i]); j++) {
        string pref, suf;
        for (int k = 0; k <= j; k++) {
          pref += a[i][k];
        }
        for (int k = j + 1; k < sz(a[i]); k++) {
          suf += a[i][k];
        }
        if (st.count(pref) && st.count(suf)) {
          ok = true;
          break;
        }
      }
      cout << ok;
    }
    cout << '\n';
  }
}