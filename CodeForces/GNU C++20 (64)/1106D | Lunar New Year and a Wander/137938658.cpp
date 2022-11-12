#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n, m;
 cin >> n >> m;
 vector<bool> seen(n);
 vector<vector<int>> adj(n);
 for (int i = 0; i < m; ++i) {
  int u, v;
  cin >> u >> v;
  --u;
  --v;
  adj[u].push_back(v);
  adj[v].push_back(u);
 }
 priority_queue<int, vector<int>, greater<int>> pq;
 pq.push(0);
 seen[0] = true;
 while (!pq.empty()) {
  int ft = pq.top();
  pq.pop();
  cout << ft + 1 << ' ';
  for (int x : adj[ft]) {
   if (!seen[x]) {
    pq.push(x);
    seen[x] = true;
   }
  }
 }
 cout << '\n';
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 