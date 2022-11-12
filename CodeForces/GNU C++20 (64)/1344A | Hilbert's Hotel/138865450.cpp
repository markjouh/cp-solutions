#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  bool ok = true;
  vector<bool> occupied(n);
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   int m = (x % n + n + i) % n;
   ok &= !occupied[m];
   occupied[m] = true;
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 