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
    string s;
    cin >> n >> s;
    int ans = 0;
    vector<bool> solved(26);
    for (int i = 0; i < sz(s); i++) {
      ans += 1 + !solved[s[i] - 'A'];
      solved[s[i] - 'A'] = true;
    }
    cout << ans << '\n';
  }
}