#include <bits/stdc++.h>
using namespace std;
 
int len(int x) {
 int res = 0;
 while (x > 0) {
  x /= 10;
  ++res;
 }
 return res;
}
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int x1, p1, x2, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  int l1 = len(x1) + p1, l2 = len(x2) + p2;
  if (l1 != l2) {
   cout << (l1 < l2 ? '<' : '>') << '\n';
  } else {
   while (len(x1) < len(x2)) {
    x1 *= 10;
   }
   while (len(x2) < len(x1)) {
    x2 *= 10;
   }
   cout << (x1 == x2 ? '=' : (x1 < x2 ? '<' : '>')) << '\n';
  }
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 