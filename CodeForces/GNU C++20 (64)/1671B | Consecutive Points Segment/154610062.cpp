#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int MXN = 2e5;
int n;
int a[MXN];
 
bool check(int l) {
  bool ok = true;
  for (int i = 0; i < n; i++)
    ok &= abs(l + i - a[i]) < 2;
  return ok;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    cout << (check(a[0] - 1) || check(a[0]) || check(a[0] + 1) ? "YES\n" : "NO\n");
  }
}