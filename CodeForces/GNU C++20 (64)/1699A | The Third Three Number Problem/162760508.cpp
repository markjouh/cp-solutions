#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      cout << n / 2 << ' ' << 0 << ' ' << 0 << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}