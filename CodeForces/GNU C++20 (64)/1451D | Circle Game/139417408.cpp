#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr); 
 int tc;
 cin >> tc;
 while (tc--) {
  long long d, k;
  cin >> d >> k;
  long long y = 0, x = 0, res = 1;
  while (y * y + x * x <= d * d) {
   res ^= 1;
   (y < x ? y : x) += k;
  }
  cout << (res ? "Ashish" : "Utkarsh") << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 