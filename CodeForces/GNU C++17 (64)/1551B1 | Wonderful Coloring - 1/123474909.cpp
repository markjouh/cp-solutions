#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  string s;
  cin >> s;
  map<char, int> m;
  for (int i = 0; i < s.size(); i++) {
   m[s[i]]++;
  }
  int a = 0, b = 0;
  for (auto x : m) {
   if (x.second == 1) {
    (a < b ? a : b)++;
   } else {
    a++;
    b++;
   }
  }
  cout << min(a, b) << '\n';
 }
}