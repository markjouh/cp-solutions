#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, b, x, y;
    cin >> n >> b >> x >> y;
    ll sum = 0, cur = 0;
    for (int i = 0; i < n; i++) {
      cur += (cur + x <= b ? x : -y);
      sum += cur;
    }
    cout << sum << '\n';
  }
}