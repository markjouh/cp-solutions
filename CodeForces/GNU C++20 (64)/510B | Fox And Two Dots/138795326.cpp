#include <bits/stdc++.h>
using namespace std;
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define each(a, b) for (auto &a : b)
#define rep(i, a, b) for (int i = a; i < (int)b; i++)
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n, m;
 cin >> n >> m;
 char grid[n + 2][m + 2] = {};
 rep(i, 1, n + 1) {
  rep(j, 1, m + 1) {
   cin >> grid[i][j];
  }
 }
 bool seen[n + 2][m + 2] = {};
 rep(i, 1, n + 1) {
  rep(j, 1, m + 1) {
   if (!seen[i][j]) {
    queue<pair<int, int>> q;
    q.push({i, j});
    while (sz(q)) {
     int f = q.front().first, s = q.front().second;
     q.pop();
     if (seen[f][s]) {
      cout << "Yes" << '\n';
      return 0;
     }
     seen[f][s] = true;
     int a[4] = {-1, 0, 1, 0}, b[4] = {0, 1, 0, -1};
     rep(k, 0, 4) {
      int y = f + a[k], x = s + b[k];
      if (grid[f][s] == grid[y][x] && !seen[y][x]) {
       q.push({y, x});
      }
     }
    }
   }
  }
 }
 cout << "No" << '\n';
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/