#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
bool psq(int x) {
  int sq = sqrt(x);
  return sq * sq == x;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
      cout << 0 << '\n';
    } else if (psq(x * x + y * y)) {
      cout << 1 << '\n';
    } else {
      cout << 2 << '\n';
    }
  }
}