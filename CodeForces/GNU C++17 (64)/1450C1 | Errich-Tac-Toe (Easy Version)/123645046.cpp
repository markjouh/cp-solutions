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
  vector<string> a(n);
  vector<int> cnt = {0, 0, 0};
  for (int i = 0; i < n; i++) {
   cin >> a[i];
   for (int j = 0; j < n; j++) {
    if (a[i][j] == 'X') {
     cnt[(i + j) % 3]++;
    }
   }
  }
  int tile = min_element(cnt.begin(), cnt.end()) - cnt.begin();
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < n; j++) {
    if (a[i][j] == 'X' && (i + j) % 3 == tile) {
     a[i][j] = 'O';
    }
   }
  }
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < n; j++) {
    cout << a[i][j];
   }
   cout << '\n';
  }
 }
}