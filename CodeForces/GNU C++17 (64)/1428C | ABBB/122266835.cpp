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
  int len = 0;
  for (int i = 0; i < s.size(); i++) {
   if (s[i] == 'B' && len > 0) {
    len--;
   } else {
    len++;
   }
  }
  cout << len << '\n';
 }
}