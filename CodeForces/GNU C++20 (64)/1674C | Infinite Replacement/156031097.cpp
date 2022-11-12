#include <bits/stdc++.h>
using namespace std;
 
#define SZ(x) (int)size(x)
#define ALL(x) begin(x), end(x)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    if (t == "a") {
      cout << 1 << '\n';
    } else if (count(ALL(t), 'a')) {
      cout << -1 << '\n';
    } else {
      long long res = 1;
      for (int i = 0; i < SZ(s); i++) {
        res *= 2;
      }
      cout << res << '\n';
    }
  }
}