#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int MXN = 2e5;
bool bits[MXN][31];
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ans &= x;
      for (int bit = 0; bit <= 30; bit++)
        bits[i][bit] = (x >> bit) & 1;
    }
    for (int bit = 30; bit >= 0; bit--) {
      int cost = 0;
      for (int i = 0; i < n; i++)
        cost += bits[i][bit] == 0;
      if (cost > 0 && cost <= k) {
        k -= cost;
        ans += pow(2, bit);
      }
    }
    cout << ans << '\n';
  }
}