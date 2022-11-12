#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<vector<int>> days(5, vector<int>(5));
  for (int rep = 0; rep < n; rep++) {
   vector<int> cur(5);
   for (int &x : cur) {
    cin >> x;
   }
   for (int i = 0; i < 5; i++) {
    if (cur[i] == 1) {
     for (int j = 0; j < 5; j++) {
      days[i][j] += cur[j];
     }
    }
   }
  }
  auto solve = [&]() {
   for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
     if (days[i][i] + days[j][j] - days[i][j] == n && abs(days[i][i] - days[j][j]) <= days[i][j]) {
      return "YES";
     }
    }
   }
   return "NO";
  };
  cout << solve() << '\n';
 }
}