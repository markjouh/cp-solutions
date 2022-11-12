#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7, mxn = 1e5 + 1;
int a[mxn], b[mxn], d[mxn], pos[mxn], g[mxn];
bool vis[mxn];
 
void mmul(int &a, int b) {
  a = ((a % mod) * (b % mod)) % mod;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pos[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      g[i] = pos[b[i]];
    }
    for (int i = 0; i < n; i++) {
      cin >> d[i];
    }
    int ans = 1;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; i++) {
      if (!vis[i] && !d[i]) {
        bool unfixed = true;
        int u = i, sz = 1;
        vis[u] = true;
        while (!vis[g[u]]) {
          u = g[u];
          vis[u] = true;
          unfixed &= !d[u];
          sz++;
        }
        if (unfixed && sz > 1) {
          mmul(ans, 2);
        }
      }
    }
    cout << ans << '\n';
  }
}