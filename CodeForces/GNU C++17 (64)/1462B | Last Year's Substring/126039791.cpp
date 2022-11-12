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
  for (int i = 0; i < n; i++) {
   string cur = s;
   cur.erase(i, n - 4);
   if (cur == "2020") {
    ok = true;
    break;
   }
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
}