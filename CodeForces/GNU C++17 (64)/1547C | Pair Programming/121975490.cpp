#include <bits/stdc++.h>
using namespace std;
 
int a[100], b[100];
 
void run_case() {
 int k, n, m;
 cin >> k >> n >> m;
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }
 for (int i = 0; i < m; i++) {
  cin >> b[i];
 }
 vector<int> res;
 int idxa = 0, idxb = 0;
 while (res.size() < n + m) {
  if (idxa < n && a[idxa] == 0) { 
   res.push_back(0);
   idxa++;
   k++;
  } else if (idxb < m && b[idxb] == 0) {
   res.push_back(0);
   idxb++;
   k++;
  } else if (idxa < n && a[idxa] <= k) {
   res.push_back(a[idxa]);
   idxa++;
  } else if (idxb < m && b[idxb] <= k) {
   res.push_back(b[idxb]);
   idxb++;
  } else {
   cout << -1 << '\n';
   return;
  }
 }
 for (int x : res) {
  cout << x << ' ';
 }
 cout << '\n';
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  run_case();
 }
}