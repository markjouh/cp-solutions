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
    vector<int> s(n), f(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> f[i];
    }
    cout << f[0] - s[0] << ' ';
    for (int i = 1; i < n; i++) {
      cout << f[i] - max(s[i], f[i - 1]) << ' ';
    }
    cout << '\n';
  }
}