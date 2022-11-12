#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
 
const int mod = 10;
 
int madd(int a, int b) {
  return (a + b) % mod;
}
 
int msub(int a, int b) {
  return (((a - b) % mod) + mod) % mod;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      int m;
      cin >> m;
      for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        if (c == 'U') {
          a[i] = msub(a[i], 1);
        } else {
          a[i] = madd(a[i], 1);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
}