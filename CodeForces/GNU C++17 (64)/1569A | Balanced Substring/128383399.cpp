#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  string s;
  cin >> n >> s;
  bool ok = false;
  for (string x : {"ab", "ba"}) {
   auto it = s.find(x);
   if (it != string::npos) {
    cout << it + 1 << ' ' << it + 2 << '\n';
    ok = true;
    break;
   }
  }
  if (!ok) {
   cout << -1 << ' ' << -1 << '\n';
  }
 }
}