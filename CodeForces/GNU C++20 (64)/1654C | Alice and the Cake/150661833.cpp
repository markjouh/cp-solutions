#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
map<ll, int> mp;
 
bool dfs(ll x) {
  if (x == 0) {
    return 0;
  }
  if (mp[x] > 0) {
    mp[x]--;
    return 1;
  }
  return dfs(x / 2) && dfs((x + 1) / 2);
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    mp.clear();
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mp[x]++;
      sum += x;
    }
    cout << (dfs(sum) ? "YES\n" : "NO\n");
  }
}