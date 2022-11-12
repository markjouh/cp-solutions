#include <bits/stdc++.h>
using namespace std;
 
int ct(string s, string f) {
  int ans = 0;
  for (int i = 0; i + f.size() - 1 < s.size(); i++) {
    bool ok = true;
    for (int j = 0; j < f.size(); j++) {
      ok &= s[i + j] == f[j];
    }
    ans += ok;
  }
  return ans;
}
 
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
    string s;
    cin >> n >> s;
    cout << ct(s, "00") * 2 + ct(s, "010") << '\n';
  }
}