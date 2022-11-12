#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> table(h, vector<int>(w));
 
  // set corners
  table[0][0] = 1;
  table[h - 1][0] = 1;
  table[0][w - 1] = 1;
  table[h - 1][w - 1] = 1;
 
  // top and bottom
  for (int x : {0, h - 1}) {
   for (int i = 1; i < w - 1; i++) {
    if (!table[x][i - 1] && !table[x][i + 1]) {
     table[x][i] = 1;
    }
   }
  }
 
  // left and right
  for (int x : {0, w - 1}) {
   for (int i = 1; i < h - 1; i++) {
    if (!table[i - 1][x] && !table[i + 1][x]) {
     table[i][x] = 1;
    }
   }
  }
 
  for (auto x : table) {
   for (auto y : x) {
    cout << y;
   }
   cout << '\n';
  }
  cout << '\n';
 }
}