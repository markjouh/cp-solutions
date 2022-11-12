#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
bool table[100][100];
 
// We can color any cell black except for the top left corner by choosing
// a cell to the top or left of it as the top left, making it black. We
// should do this in bottom to top, right to left order to avoid messing up
// past operations.
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        table[i][j] = s[j] - '0';
        sum += table[i][j];
      }
    }
    if (table[0][0]) {
      cout << "-1\n";
      continue;
    }
    cout << sum << '\n';
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (table[i][j]) {
          if (j > 0) {
            cout << i + 1 << ' ' << j << ' ' << i + 1 << ' ' << j + 1 << '\n';
          } else {
            cout << i << ' ' << j + 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
          }
        }
      }
    }
  }
}