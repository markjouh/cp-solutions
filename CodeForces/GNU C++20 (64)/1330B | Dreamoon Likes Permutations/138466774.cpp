#include <bits/stdc++.h>
using namespace std;
 
bool ck(vector<int> a, int m) {
 int n = a.size();
 vector<int> ct(m + 1);
 for (int i = 0; i < m; i++) {
  ct[a[i]]++;
 }
 for (int i = 1; i <= m; i++) {
  if (ct[i] != 1) {
   return false;
  }
 }
 fill(ct.begin(), ct.end(), 0);
 for (int i = m; i < n; i++) {
  ct[a[i]]++;
 }
 for (int i = 1; i <= n - m; i++) {
  if (ct[i] != 1) {
   return false;
  }
 }
 return true;
}
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
   int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  vector<pair<int, int>> res;
  int m = *max_element(a.begin(), a.end());
  if (ck(a, m)) {
   res.push_back({m, n - m});
  }
  reverse(a.begin(), a.end());
  if (m != n - m && ck(a, m)) {
   res.push_back({n - m, m});
  }
  cout << res.size() << '\n';
  for (auto [f, s] : res) {
   cout << f << ' ' << s << '\n';
  }
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 