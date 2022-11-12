#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i = a; i < (int)b; i++)
#define per(i, a, b) for (int i = b-1; i >= (int)a; i--)
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == i+1) {
      ans = max(ans, i);
    }
    if (a[i] + n-i-1 == 1e3) {
      ans = max(ans, n-i-1);
    }
    for (int j = 0; j < i; j++) {
      if (a[i]-a[j] == i-j) {
        ans = max(ans, i-j-1);
      }
    }
  }
  cout << ans << '\n';
}