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
  vector<string> chk{"aa", "aba", "aca", "abca", "acba", "abbacca", "accabba"};
  bool ok = false;
  for (string substr : chk) {
   if (s.find(substr) != string::npos) {
    cout << substr.size() << '\n';
    ok = true;
    break;
   }
  }
  if (!ok) {
   cout << -1 << '\n';
  }
 }
}