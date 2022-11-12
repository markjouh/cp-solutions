#include <bits/stdc++.h>
using namespace std;
 
bool solve() {
 string s, t;
 cin >> s >> t;
 int n = s.size();
 for (int i = 0; i < n; i++) {
  string a;
  a.push_back(s[i]);
  for (int j = i; j < n; j++) {
   if (j != i) {
    a.push_back(s[j]);
   }
   string b = a;
   for (int k = j; k >= 0; k--) {
    if (k != j) {
     b.push_back(s[k]);
    }
    if (b == t) {
     return true;
    }
   }
  }
 }
 return false;
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int T;
 cin >> T;
 while (T--) {
  
  cout << (solve() ? "YES" : "NO") << '\n';
 }
}