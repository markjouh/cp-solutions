#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int& x : a) {
   cin >> x;
  }
  for (int& x : b) {
   cin >> x;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  bool ok = true;
  for (int i = 0; i < n; ++i) {
   int diff = b[i] - a[i];
   ok &= diff == 0 || diff == 1;
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
}