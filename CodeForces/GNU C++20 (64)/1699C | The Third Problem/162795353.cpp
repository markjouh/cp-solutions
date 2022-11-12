#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int mod = 1e9 + 7;
 
void mmul(ll &a, ll b) {
  a = (a * b) % mod;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pos[x] = i;
    }
    ll ans = 1;
    int l = min(pos[0], pos[1]), r = max(pos[0], pos[1]);
    for (int i = 2; i < n; i++) {
      if (pos[i] >= l && pos[i] <= r) {
        mmul(ans, r - l + 1 - i);
      } else {
        l = min(l, pos[i]);
        r = max(r, pos[i]);
      }
    }
    cout << ans << '\n';
  }
}