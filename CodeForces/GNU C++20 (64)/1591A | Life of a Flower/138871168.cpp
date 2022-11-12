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
  int height = 1, last = -1;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   if (x == 0 && last == 0) {
    ok = false; 
   }
   if (x == 1 && last == 1) {
    height += 5;
   } else if (x == 1) {
    height++;
   }
   last = x;
  }
  cout << (ok ? height : -1) << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 