#include <bits/stdc++.h>
using namespace std;
 
char arr[400][400];
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < n; j++) {
    cin >> arr[i][j];
    if (arr[i][j] == '*') {
     v.push_back({i, j});
    }
   }
  }
  if (v[0].first == v[1].first) {
   v[0].first += (v[0].first > 0 ? -1 : 1);
  }
  if (v[0].second == v[1].second) {
   v[0].second += (v[0].second > 0 ? -1 : 1);
  }
  arr[v[0].first][v[0].second] = '*';
  arr[v[0].first][v[1].second] = '*';
  arr[v[1].first][v[0].second] = '*';
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < n; j++) {
    cout << arr[i][j];
   }
   cout << '\n';
  }
 }
}