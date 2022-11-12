#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
struct UF {
 int n;
 vector<int> parent, rank;
 UF(int _n) : n(_n) {
  parent.resize(n);
  iota(parent.begin(), parent.end(), 0);
  rank.resize(n);
 }
 int get(int x) {
  if (x == parent[x]) {
   return x;
  }
  return get(parent[x]);
 }
 void unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) {
   return;
  }
  if (rank[x] < rank[y]) {
   swap(x, y);
  }
  parent[y] = x;
  if (rank[x] == rank[y]) {
   rank[x]++;
  }
 }
};
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n, m1, m2;
 cin >> n >> m1 >> m2;
 UF mocha(n), diana(n);
 while (m1--) {
  int u, v;
  cin >> u >> v;
  mocha.unite(u - 1, v - 1);
 }
 while (m2--) {
  int u, v;
  cin >> u >> v;
  diana.unite(u - 1, v - 1);
 }
 vector<pair<int, int>> res;
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < n; j++) {
   if (mocha.get(i) != mocha.get(j) && diana.get(i) != diana.get(j)) {
    mocha.unite(i, j);
    diana.unite(i, j);
    res.push_back({i + 1, j + 1});
   }
  }
 }
 cout << res.size() << '\n';
 for (auto [x, y] : res) {
  cout << x << ' ' << y << '\n';
 }
}