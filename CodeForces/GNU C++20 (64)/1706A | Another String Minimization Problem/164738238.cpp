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
    int n, m;
    cin >> n >> m;
    string res(m, 'B');
    for (int i = 0; i < n; i++) {
      int idx;
      cin >> idx;
      idx--;
      idx = min(idx, m - idx - 1);
      (res[idx] == 'B' ? res[idx] : res[m - idx - 1]) = 'A';
    }
    cout << res << '\n';
  }
}