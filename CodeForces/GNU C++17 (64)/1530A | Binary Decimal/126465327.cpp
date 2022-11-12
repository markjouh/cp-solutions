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
  char mx = '0';
  for (char c : s) {
   mx = max(mx, c);
  }
  cout << mx << '\n';
 }
}