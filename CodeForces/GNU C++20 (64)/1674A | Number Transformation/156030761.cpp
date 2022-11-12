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
    int x, y;
    cin >> x >> y;
    if (y % x != 0) {
      cout << "0 0\n";
      continue;
    }
    cout << 1 << ' ' << y / x << '\n';
  }
}