#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) {
      cin >> x;
    }
    for (int &x : b) {
      cin >> x;
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
      ans += min(abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1]), abs(a[i] - b[i + 1]) + abs(b[i] - a[i + 1]));
    }
    cout << ans << '\n';
  }
}