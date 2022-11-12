#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int MXN = 2e5;
ll pre[MXN];
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
      cin >> pre[i];
    sort(pre, pre + n);
    for (int i = 1; i < n; i++)
      pre[i] += pre[i - 1];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      if (k >= pre[i])
        ans += (k - pre[i]) / (i + 1) + 1;
    }
    cout << ans << '\n';
  }
}