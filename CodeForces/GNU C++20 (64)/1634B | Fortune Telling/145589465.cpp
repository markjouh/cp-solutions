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
    ll n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a += x;
    }
    cout << (a % 2 == b % 2 ? "Alice\n" : "Bob\n");
  }
}