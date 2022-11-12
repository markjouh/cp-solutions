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
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  sort(a.begin(), a.end());
  bool ok = true;
  for (int i = 1; i < a.size(); i++) {
   ok &= a[i] - a[i - 1] <= 1;
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
}