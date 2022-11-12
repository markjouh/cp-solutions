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
    char a, b, c, d;
    cin >> a >> b >> c >> d;
    int sum = (a - '0') + (b - '0') + (c - '0') + (d - '0');
    if (sum == 0) {
      cout << 0 << '\n';
    } else if (sum == 4) {
      cout << 2 << '\n';
    } else {
      cout << 1 << '\n';
    }
  }
}