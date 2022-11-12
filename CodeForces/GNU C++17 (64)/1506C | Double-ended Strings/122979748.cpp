#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  string a, b;
  cin >> a >> b;
  if (a.size() > b.size()) {
   swap(a, b);
  }
  int ans = a.size() + b.size();
  for (int i = 0; i < a.size(); i++) {
   for (int j = 1; j <= a.size() - i; j++) {
    if (b.find(a.substr(i, j)) != string::npos) {
     int cur = a.size() + b.size() - j * 2;
     ans = min(ans, cur);
    }
   }
  }
  cout << ans << '\n';
 }
}