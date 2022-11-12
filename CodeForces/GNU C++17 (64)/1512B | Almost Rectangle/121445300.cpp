#include <bits/stdc++.h>
using namespace std;
 
char arr[400][400];
vector<pair<int, int>> v;
 
void gridfill() {
 for (int i = 0; i < v.size(); i++) {
  for (int j = i + 1; j < v.size(); j++) {
   if (v[i].first == v[j].first) {
    if (v[i].first > 0) {
     v[i].first--;
    } else {
     v[i].first++;
    }
    arr[v[i].first][v[i].second] = '*';
   } else if (v[i].second == v[j].second) {
    if (v[i].second > 0) {
     v[i].second--;
    } else {
     v[i].second++;
    }
    arr[v[i].first][v[i].second] = '*';
   }
   if (v[i].first != v[j].first && v[i].second != v[j].second) {
    arr[v[i].first][v[j].second] = '*';
    arr[v[j].first][v[i].second] = '*';
    return;
   }
  }
 }
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < n; j++) {
    cin >> arr[i][j];
    if (arr[i][j] == '*') {
     v.push_back({i, j});
    }
   }
  }
  gridfill();
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < n; j++) {
    cout << arr[i][j];
   }
   cout << '\n';
  }
  v.clear();
 }
}