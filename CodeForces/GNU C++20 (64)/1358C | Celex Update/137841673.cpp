#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
   int y1, x1, y2, x2;
   cin >> y1 >> x1 >> y2 >> x2;
   long long a = y2 - y1, b = x2 - x1;
   cout << a * b + 1 << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Try to think of ideas from past problems
  Check for edge cases, overflow, etc.
*/