#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  string a, b;
  cin >> n >> a >> b;
  bool ok = true;
  for (int i = 0; i < n; i++) {
   if (a[i] == '1' && b[i] == '1') {
    ok = false;
    break;
   }
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
}