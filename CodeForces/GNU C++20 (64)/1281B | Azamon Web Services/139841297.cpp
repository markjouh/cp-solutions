#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int T;
 cin >> T;
 while (T--) {
  string s, c;
  cin >> s >> c;
  int n = s.size();
  string best = s;
  char mn = s[n - 1];
  int id = n - 1;
  for (int i = n - 2; i >= 0; i--) {
   if (s[i] > mn) {
    string cur = s;
    swap(cur[i], cur[id]);
    best = min(best, cur);
   }
   if (s[i] < mn) {
    mn = s[i];
    id = i;
   }
  }
  cout << (best < c ? best : "---") << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/