#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      ans |= x;
    }
    cout << ans << '\n';
  }
}