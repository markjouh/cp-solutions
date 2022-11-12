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
  string s;
  cin >> n >> s;
  bool ok = true;
  vector<vector<char>> a(n, vector<char>(n, ' '));
  for (int i = 0; i < n; i++) {
   bool flag = true;
   for (int j = 0; j < n; j++) {
    if (a[i][j] != ' ') {
     continue;
    }
    if (i == j) {
     a[i][j] = 'X';
    } else if (s[j] != '1' && flag) {
     a[i][j] = '+';
     a[j][i] = '-';
     flag = false;
    } else {
     a[i][j] = '=';
    }
   }
   if (s[i] == '2' && flag) {
    ok = false;
   }
  }
  cout << (ok ? "YES" : "NO") << '\n';
  if (ok) {
   for (auto x : a) {
    for (char y : x) {
     cout << y;
    }
    cout << '\n';
   }
  }
 }
}