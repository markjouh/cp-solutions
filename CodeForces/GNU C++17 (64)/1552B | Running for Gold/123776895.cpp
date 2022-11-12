#include <bits/stdc++.h>
using namespace std;
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(5, 0));
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < 5; j++) {
    cin >> a[i][j];
   }
  }
  int idx = 0;
  for (int i = 1; i < n; i++) {
   int cnt = 0;
   for (int j = 0; j < 5; j++) {
    if (a[idx][j] < a[i][j]) {
     cnt++;
    }
   }
   if (cnt < 3) {
    idx = i;
   }
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
   int cnt = 0;
   for (int j = 0; j < 5; j++) {
    if (a[idx][j] < a[i][j]) {
     cnt++;
    }
   }
   if (cnt < 3 && idx != i) {
    ok = false;
    break;
   }
  }
  cout << (ok ? idx + 1 : -1) << '\n';
 }
}