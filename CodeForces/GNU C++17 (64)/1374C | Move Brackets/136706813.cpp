#include <bits/stdc++.h>
using namespace std;
 
// Actually read the problem
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  string s;
  cin >> n >> s;
  int bal = 0, ans = 0;
  for (char c : s) {
   bal += (c == '(' ? 1 : -1);
   ans = max(ans, -bal);
  }
  cout << ans << '\n';
 }
}