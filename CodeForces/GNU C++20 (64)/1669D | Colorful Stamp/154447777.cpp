#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    string s;
    cin >> n >> s;
    if (s.back() != 'W')
      s += 'W';
    bool ok = true;
    set<char> st;
    for (char c : s) {
      if (c == 'W') {
        ok &= st.size() == 0 || st.size() == 2;
        st.clear();
        continue;
      }
      st.insert(c);
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}