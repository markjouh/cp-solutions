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
    cout << "Division ";
    if (n >= 1900)
      cout << 1 << '\n';
    else if (n >= 1600)
      cout << 2 << '\n';
    else if (n >= 1400)
      cout << 3 << '\n';
    else
      cout << 4 << '\n';
  }
}