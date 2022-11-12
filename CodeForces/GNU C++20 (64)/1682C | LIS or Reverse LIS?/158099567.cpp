#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mp[x]++;
    }
    int ans = 0, indiv = 0;
    for (auto [f, s] : mp) {
      s > 1 ? ans++ : indiv++;
    }
    ans += (indiv + 1) / 2;
    cout << ans << '\n';
  }
}