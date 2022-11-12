#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<vector<int>> a(n, vector<int>(n));
 for (int i = 0; i < n; i++) {
  cin >> a[i][i];
 }
 for (int i = n - 1; i >= 0; i--) {
  int x = i, y = i;
  for (int j = 0; j < a[i][i] - 1; j++) {
   if (y < n - 1 && a[y + 1][x] == 0) {
    y++;
   } else {
    x--;
   }
   a[y][x] = a[i][i];
  }
 }
 for (auto x : a) {
  for (int y : x) {
   if (y) {
    cout << y << ' ';
   } else {
    cout << "  ";
   }
  }
  cout << '\n';
 }
}