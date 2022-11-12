#include <bits/stdc++.h>
using namespace std;
 
const int mxn = 100;
 
int a[mxn], b[mxn];
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    int amx = 0, bmx = 0;
    for (int i = 0; i < n; i++) {
      amx = max(amx, max(a[i], b[i]));
      bmx = max(bmx, min(a[i], b[i]));
    }
    cout << amx * bmx << '\n';
  }
}