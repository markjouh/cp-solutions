#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr); 
 int tc;
 cin >> tc;
 while (tc--) {
  vector<int> a(7);
  for (int &x : a) {
   cin >> x;
  }
  cout << a[0] << ' ' << a[1] << ' ' << a[6] - a[0] - a[1] << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 