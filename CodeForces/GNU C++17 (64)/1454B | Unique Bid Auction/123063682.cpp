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
  map<int, int> m;
  for (int i = 0; i < n; i++) {
   int a;
   cin >> a;
   if (m.count(a)) {
    m[a] = -1;
   } else {
    m[a] = i + 1;
   }
  }
  int mn = INT_MAX, pos = -1;
  for (auto [x, y] : m) {
   if (y != -1 && x < mn) {
    mn = x;
    pos = y;
   }
  }
  cout << pos << '\n';
 }
}