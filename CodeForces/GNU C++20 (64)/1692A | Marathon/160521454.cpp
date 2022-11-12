#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (b > a) + (c > a) + (d > a) << '\n';
  }
}