#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully!
 
int solve(string a, string b) {
 if (count(a.begin(), a.end(), '0') != count(b.begin(), b.end(), '0')) {
  return 1e9;
 }
 int res = 0;
 for (int i = 0; i < int(a.size()); i++) {
  res += a[i] != b[i];
 }
 return res;
}
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  string a, b;
  cin >> n >> a >> b;
  int ans = solve(a, b);
  for (char &c : a) {
   c = (c == '0' ? '1' : '0');
  }
  bool flag = false;
  for (int i = 0; i < n; i++) {
   if (a[i] == '0' && b[i] == '1') {
    a[i] = '1';
    flag = true;
    break;
   }
  }
  if (!flag) {
   for (int i = 0; i < n; i++) {
    if (a[i] == '0') {
     a[i] = '1';
     flag = true;
     break;
    }
   }
  }
  if (flag) {
   ans = min(ans, solve(a, b)+1);
  }
  cout << (ans == 1e9 ? -1 : ans) << '\n';
 }
}