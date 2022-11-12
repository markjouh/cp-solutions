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
  vector<int> weight(n), degree(n);
  for (int &x : weight) {
   cin >> x;
  }
  for (int i = 0; i < n - 1; i++) {
   int u, v;
   cin >> u >> v;
   degree[u - 1]++;
   degree[v - 1]++;
  }
  ll ans = 0;
  vector<int> add;
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < degree[i] - 1; j++) {
    add.push_back(weight[i]);
   }
   ans += weight[i];
  }
  sort(add.begin(), add.end(), greater<int>());
  for (int x : add) {
   cout << ans << ' ';
   ans += x;
  }
  cout << ans << '\n';
 }
}