#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, m, minsz;
  cin >> n >> m >> minsz;
  vector<vector<int>> status(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
   for (int j = 0; j < m; ++j) {
    char c;
    cin >> c;
    status[i][j] = c == '*';
   }
  }
  for (int i = 0; i < n; ++i) {
   for (int j = 0; j < m; ++j) {
    if (status[i][j]) {
     int sz = 0;
     while (i - sz >= 0 && j - sz >= 0 && j + sz < m && status[i - sz][j - sz] && status[i - sz][j + sz]) {
      sz++;
     }
     if (sz > minsz) {
      for (int k = 0; k < sz; ++k) {
       status[i - k][j - k] = 2;
       status[i - k][j + k] = 2;
      }
     }
    }
   }
  }
  bool ok = true;
  for (int i = 0; i < n; ++i) {
   for (int j = 0; j < m; ++j) {
    ok &= status[i][j] != 1;
   }
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
}