#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
   v[i] = s[i] - '0';
  }
  for (int i = 0; i < m; i++) {
   vector<int> cur = v;
   for (int j = 0; j < n; j++) {
    int sum = 0;
    if (j > 0 && v[j - 1]) {
     sum++;
    }
    if (j < n - 1 && v[j + 1]) {
     sum++;
    }
    if (sum == 1) {
     cur[j] = 1;
    }
   }
   if (v == cur) {
    break;
   } else {
    v = cur;
   }
  }
  for (int x : v) {
   cout << x;
  }
  cout << '\n';
 }
}