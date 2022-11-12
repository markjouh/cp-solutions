#include <bits/stdc++.h>
 
using namespace std;
 
void solveCase() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = s[i] - 'a';
  }
  // We never have to perform the operation more than once
  vector<bool> operation(26);
  for (int i = 0; i < n; i++) {
    while (a[i] > 0) {
      if (operation[a[i]]) {
        a[i]--;
      } else if (k > 0) {
        operation[a[i]] = true;
        k--;
        a[i]--;
      } else {
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << char('a' + a[i]);
  }
  cout << '\n';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int cases;
  cin >> cases;
  while (cases--) {
    solveCase();
  }
}