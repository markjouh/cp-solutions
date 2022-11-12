#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int T;
 cin >> T;
 while (T--) {
  string s;
  cin >> s;
  int n = s.size();
  bool ok = n % 2 == 0;
  for (int i = 0; i < n / 2; i++)
  {
   ok &= s[i] == s[i + n / 2];
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/