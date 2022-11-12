#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  int cnt0 = 0, cnt1 = 0;
  map<int, int> mp;
  mp[0] = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      cnt0++;
    } else {
      cnt1++;
    }
    int dist = cnt0 - cnt1;
    if (mp.contains(dist)) {
      ans = max(ans, i - mp[dist]);
    } else {
     mp[dist] = i;
    }
  }
  cout << ans << '\n';
}