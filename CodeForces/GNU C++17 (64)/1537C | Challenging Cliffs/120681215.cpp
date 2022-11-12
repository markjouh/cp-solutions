#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> v(n), ans;
  for (int &x : v) cin >> x;
  sort(v.begin(), v.end());
  int mn = 2e9, pos;
  for (int i = 1; i < n; i++) {
   if (v[i] - v[i - 1] < mn) {
    mn = v[i] - v[i - 1];
    pos = i;
   }
  }
  for (int i = pos; i < n; i++) ans.push_back(v[i]);
  for (int i = 0; i < pos; i++) ans.push_back(v[i]);
  if (n == 2) reverse(ans.begin(), ans.end());
  for (int x : ans) cout << x << ' ';
  cout << '\n';
 }
}