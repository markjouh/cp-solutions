#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    if (k != 1 && (n * k % 2 != 0 || n % 2)) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    int odd = 1, even = 2;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        cout << (i % 2 == 0 ? odd : even) << ' ';
        (i % 2 == 0 ? odd : even) += 2;
      }
      cout << '\n';
    }
  }
}