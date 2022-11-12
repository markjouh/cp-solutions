#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<int> a(n), ct(n);
    for (int &x : a) {
      cin >> x;
    }
    auto peak = [&](int i) {
      if (i == 0 || i == n-1) {
        return false;
      }
      return a[i] > a[i-1] && a[i] > a[i+1];
    };
    int ans = 0;
    for (int i = 1; i < n-1; i++) {
      if (peak(i-1) && peak(i+1)) {
        a[i] = max(a[i-1],a[i+1]);
        ans++;
      }
    }
    for (int i = 1; i < n-1; i++) {
      if (peak(i)) {
        a[i] = max(a[i-1],a[i+1]);
        ans++;
      }
    }
    cout << ans << '\n'; 
    for (int x : a) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
 