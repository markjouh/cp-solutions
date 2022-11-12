#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int MXN = 2e5 + 1;
int w[MXN];
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> w[i];
    map<int, int> mp;
    int cur_suf = 0;
    for (int i = n - 1; i >= 0; i--) {
      cur_suf += w[i];
      mp[cur_suf] = n - i;
    }
    int cur_pre = 0;
    int maxw = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      cur_pre += w[i];
      mp.erase(prev(mp.end()));
      if (mp.count(cur_pre) && cur_pre * 2 >= maxw) {
        maxw = cur_pre * 2;
        ans = max(ans, i + 1 + mp[cur_pre]);
      }
    }
    cout << ans << '\n';
  }
}