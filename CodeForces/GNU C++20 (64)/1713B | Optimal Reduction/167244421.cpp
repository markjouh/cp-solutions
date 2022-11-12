#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    ll best = *max_element(a.begin(), a.end());
    ll rng = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      if (rng < a[i]) {
        ans += a[i] - rng;
        rng = a[i];
      }
      if (rng > a[i]) {
        rng = a[i];
      }
    }
    cout << (ans <= best ? "YES\n" : "NO\n");
  }
}