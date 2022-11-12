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
    vector<bool> vis(n + 1);
    cout << 2 << '\n';
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j *= 2) {
        if (!vis[j]) {
          cout << j << ' ';
          vis[j] = true;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        cout << i << ' ';
      }
    }
    cout << '\n';
  }
}