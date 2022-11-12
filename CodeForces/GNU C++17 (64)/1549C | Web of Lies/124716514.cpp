#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.tie(0);
 cin.sync_with_stdio(0);
 int n, m;
 cin >> n >> m;
 vector<int> a(n + 1);
 int res = 0;
 for (int i = 0; i < m; i++) {
  int u, v;
  cin >> u >> v;
  u = min(u, v);
  a[u]++;
  if (a[u] == 1) {
   res++;
  }
 }
 int q;
 cin >> q;
 for (int i = 0; i < q; i++) {
  int t, u, v;
  cin >> t;
  if (t != 3) {
   cin >> u >> v;
   u = min(u, v);
  }
  if (t == 1) {
   a[u]++;
   if (a[u] == 1) {
    res++;
   }
  } else if (t == 2) {
   a[u]--;
   if (a[u] == 0) {
    res--;
   }
  } else {
   cout << n - res << '\n';
  }
 }
}