#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    bool ok = true;
    ok &= s[0] == 'y' || s[0] == 'Y';
    ok &= s[1] == 'e' || s[1] == 'E';
    ok &= s[2] == 's' || s[2] == 'S';
    cout << (ok ? "YES\n" : "NO\n");
  }
}