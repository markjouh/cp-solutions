#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int chops = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      chops += x - 1;
    }
    cout << (chops % 2 ? "errorgorn\n" : "maomao90\n");
  }
}