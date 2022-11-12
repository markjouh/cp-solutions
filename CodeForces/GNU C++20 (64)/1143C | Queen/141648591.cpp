#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int par[n];
  bool nresp[n], cnresp[n];
  for (int i = 0; i < n; i++) {
    cin >> par[i] >> nresp[i];
    par[i]--;
  }
  // Do all this vertex's children disrespect it?
  fill(cnresp, cnresp+n, true);
  for (int i = 0; i < n; i++) {
    cnresp[par[i]] &= nresp[i];
  }
  // For each vertex, if it doesn't respect its parent and none of its children respect it, push to res
  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (nresp[i] && cnresp[i]) {
      res.push_back(i);
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