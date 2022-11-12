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
  vector<int> a(n), b(n + 1, 1);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  n = unique(a.begin(), a.end()) - a.begin();
  a.resize(n);
  for (int i = 0; i < n; i++) {
   b[a[i]]++;
  }
  b[a[0]]--;
  b[a[n - 1]]--;
  int mn = INT_MAX;
  for (int i = 0; i < n; i++) {
   mn = min(mn, b[a[i]]);
  }
  cout << mn << '\n';
 }
}