// Just finishing up a problem in my "Unsolved problems" list
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr); 
 int n;
 cin >> n;
 long long res = 0, add = 1;
 for (int i = 1; i <= n; i++) {
  add *= 2;
  res += add;
 }
 cout << res << '\n';
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 