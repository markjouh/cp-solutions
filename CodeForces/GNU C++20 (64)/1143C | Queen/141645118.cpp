#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int par[n];
  bool nresp[n], cnresp[n], exists[n];
  for (int i = 0; i < n; i++) {
    cin >> par[i] >> nresp[i];
    par[i]--;
  }
  // Do all this vertex's children disrespect it?
  fill(cnresp, cnresp+n, true);
  for (int i = 0; i < n; i++) {
    cnresp[par[i]] &= nresp[i];
  }
  // For each vertex, if nresp[index] = 1 for par[i] and all children[i], push to a queue
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (nresp[i] && cnresp[i]) {
      q.push(i);
    }
  }
  vector<int> res;
  fill(exists, exists+n, true);
  while (q.size()) {
    int t = q.front();
    q.pop();
    if (!exists[t]) {
      continue;
    }
    res.push_back(t);
    exists[t] = false;
    if (exists[par[t]] && nresp[par[t]] && cnresp[par[t]]) {
      q.push(par[t]);
    }
  }
  if (res.empty()) {
    cout << -1 << '\n';
    return 0;
  }
  for (int x : res) {
    cout << x+1 << ' ';
  }
  cout << '\n';
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/