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
  for (int i = 0; i < n; i++) {
   cin >> a[i] >> b[i];
  }
  auto solve = [&](vector<int> v) {
   sort(v.begin(), v.end());
   return v[v.size() / 2] - v[(v.size() - 1) / 2] + 1;
  };
  cout << 1ll * solve(a) * solve(b) << '\n';
 }
}