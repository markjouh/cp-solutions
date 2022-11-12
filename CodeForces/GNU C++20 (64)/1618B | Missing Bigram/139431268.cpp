#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  string res;
  cin >> n >> res;
  for (int i = 0; i < n - 3; i++) {
   string s;
   cin >> s;
   if (s[0] == res.back()) {
    res += s[1];
   } else {
    res += s;
   }
  }
  if ((int)res.size() < n) {
   res += 'a';
  }
  cout << res << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/