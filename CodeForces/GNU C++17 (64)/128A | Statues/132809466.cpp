#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 vector<vector<bool>> statue(8, vector<bool>(8)), ok(8, vector<bool>(8));
 for (int i = 0; i < 8; ++i) {
  for (int j = 0; j < 8; ++j) {
   char c;
   cin >> c;
   if (c == 'S') {
    statue[i][j] = true;
   }
  }
 }
 ok[7][0] = true;
 for (int rep = 0; rep < 8; ++rep) {
  vector<vector<bool>> cur = ok;
  for (int i = 0; i < 8; ++i) {
   for (int j = 0; j < 8; ++j) {
    if (ok[i][j]) {
     for (int a = -1; a <= 1; ++a) {
      for (int b = -1; b <= 1; ++b) {
       int x = i + a, y = j + b;
       if (x >= 0 && x < 8 && y >= 0 && y < 8 && !statue[x][y]) {
        cur[x][y] = true;
       }
      }
     }
    }
   }
  }
  ok = cur;
  for (int i = 0; i < 8; ++i) {
   statue[7][i] = false;
  }
  for (int i = 6; i >= 0; --i) {
   for (int j = 0; j < 8; ++j) {
    if (statue[i][j]) {
     statue[i][j] = false;
     statue[i + 1][j] = true;
     ok[i + 1][j] = false;
    }
   }
  }
 }
 bool res = false;
 for (int i = 0; i < 8; ++i) {
  for (int j = 0; j < 8; ++j) {
   res |= ok[i][j];
  }
 }
 cout << (res ? "WIN" : "LOSE") << '\n';
}