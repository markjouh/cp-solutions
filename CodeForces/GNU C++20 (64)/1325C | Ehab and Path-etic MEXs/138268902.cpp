#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> adj(n);
 vector<pair<int, int>> edge(n - 1);
 for (int i = 0; i < n - 1; ++i) {
  int u, v;
  cin >> u >> v;
  --u;
  --v;
  ++adj[u];
  ++adj[v];
  edge[i] = {u, v};
 }
 int l = 0, r = n - 2;
 vector<int> res(n - 1);
 for (int i = 0; i < n - 1; ++i) {
  if (adj[edge[i].first] == 1 || adj[edge[i].second] == 1) {
   res[i] = l++;
  } else {
   res[i] = r--;
  }
 }
 for (int x : res) {
  cout << x << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 
 