#include <bits/stdc++.h>
using namespace std;
 
int n, m;
char arr[50][50], res[50][50];
 
bool check(char cur) {
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < m; j++) {
   if (arr[i][j] != cur && arr[i][j] != '.') {
    return false;
   }
   res[i][j] = cur;
   cur = (cur == 'R' ? 'W' : 'R');
  }
  if (m % 2 == 0) {
   cur = (cur == 'R' ? 'W' : 'R');
  }
 }
 return true;
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    cin >> arr[i][j];
   }
  }
  if (check('R')) {
   cout << "YES" << '\n';
   for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
     cout << res[i][j];
    }
    cout << '\n';
   }
  } else if (check('W')) {
   cout << "YES" << '\n';
   for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
     cout << res[i][j];
    }
    cout << '\n';
   }
  } else {
   cout << "NO" << '\n';
  }
 }
}