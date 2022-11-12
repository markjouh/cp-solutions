#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int &x : a) {
   cin >> x;
  }
  for (int &x : b) {
   cin >> x;
  }
  for (int i = 1; i < n; i++) {
   a[i] += a[i - 1];
   b[i] += b[i - 1];
  }
  int mn = INT_MAX;
  for (int i = 0; i < n; i++) {
   int cur = max(a[n - 1] - a[i], (i > 0 ? b[i - 1] : 0));
   mn = min(mn, cur);
  }
  cout << mn << '\n';
 }
}