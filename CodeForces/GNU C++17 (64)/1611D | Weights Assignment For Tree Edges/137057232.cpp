#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> par(n + 1), weight(n + 1);
  for (int i = 1; i <= n; ++i) {
   int x;
   cin >> x;
   par[i] = x;
  }
  for (int i = 1; i <= n; ++i) {
   int x;
   cin >> x;
   weight[x] = i;
  }
  bool ok = true;
  for (int i = 1; i <= n; ++i) {
   ok &= weight[i] - weight[par[i]] >= 0;
  }
  if (!ok) {
   cout << -1 << '\n';
   continue;
  }
  for (int i = 1; i <= n; ++i) {
   cout << weight[i] - weight[par[i]] << ' ';
  }
  cout << '\n';
 }
}