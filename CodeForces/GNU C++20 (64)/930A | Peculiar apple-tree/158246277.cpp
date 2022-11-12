#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int par;
    cin >> par;
    g[par - 1].push_back(i);
  }
  vector<bool> rem(n);
  queue<pair<int, int>> q;
  q.push({0, 0});
  while (!q.empty()) {
    int u = q.front().first, dep = q.front().second;
    q.pop();
    rem[dep] = 1 - rem[dep];
    for (int v : g[u]) {
      q.push({v, dep + 1});
    }
  }
  cout << accumulate(rem.begin(), rem.end(), 0);
}