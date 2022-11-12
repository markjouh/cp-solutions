#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
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
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
 
    vector<ll> cost(n);
    for (int i = 1; i < n - 1; i++) {
      cost[i] = max(0ll, max(h[i - 1], h[i + 1]) + 1 - h[i]);
    }
 
    vector<ll> even(n), odd(n);
    for (int i = 1; i < n - 1; i++) {
      even[i] += even[i - 1];
      odd[i] += odd[i - 1];
      (i % 2 ? odd : even)[i] += cost[i];
    }
    even[n - 1] += even[n - 2];
    odd[n - 1] += odd[n - 2];
 
    if (n % 2) {
      cout << odd[n - 1] << '\n';
    } else {
      ll ans = min(even[n - 1], odd[n - 1]);
      ll cur = 0;
      for (int i = n - 2; i >= 2; i -= 2) {
        cur += cost[i];
        ans = min(ans, cur + odd[i - 2]);
      }
      cout << ans << '\n';
    }
  }
}