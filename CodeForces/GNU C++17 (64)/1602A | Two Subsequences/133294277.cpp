#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  string s;
  cin >> s;
  int idx = 0;
  char min = 'z' + 1;
  for (int i = 0; i < s.size(); ++i) {
   if (s[i] < min) {
    min = s[i];
    idx = i;
   }
  }
  cout << s[idx] << ' ';
  for (int i = 0; i < s.size(); ++i) {
   if (i != idx) {
    cout << s[i];
   }
  }
  cout << '\n';
 }
}