#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, m;
  cin >> n >> m;
  bool ok = false;
  for (int i = 0; i < n; i++) {
   vector<int> a(4);
   for (int &x : a) {
    cin >> x;
   }
   if (a[1] == a[2]) {
    ok = true;
   }
  }
  cout << (m % 2 == 0 && ok ? "YES" : "NO") << '\n';
 }
}