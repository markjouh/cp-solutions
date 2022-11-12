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
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
   cin >> v[i].first;
   v[i].second = i + 1;
  }
  sort(v.begin(), v.end());
  if (v[0].first == v[1].first) {
   cout << v[n - 1].second << '\n';
  } else {
   cout << v[0].second << '\n';
  }
 }
}