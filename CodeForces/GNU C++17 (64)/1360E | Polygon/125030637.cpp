#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.tie(0);
 cin.sync_with_stdio(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<vector<char>> a(n + 2, vector<char>(n + 2));
  for (int i = 1; i <= n; i++) {
   for (int j = 1; j <= n; j++) {
    cin >> a[i][j];
   }
  }
  bool ok = true;
  for (int i = 1; i <= n; i++) {
   for (int j = 1; j <= n; j++) {
    if (a[i][j] == '1' && i != n && j != n && a[i + 1][j] != '1' && a[i][j + 1] != '1') {
     ok = false;
    } 
   }
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
}