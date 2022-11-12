#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> sq;
  for (int i = 0; i * i <= 2e5; i++) {
    sq.push_back(i * i);
  }
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int rem = n, sz = n;
    vector<int> res(n);
    for (int i = n - 1; i >= 0;) {
      int lb = *lower_bound(sq.begin(), sq.end(), i);
      while (lb - i < sz) {
        res[i] = lb - i;
        i--;
        rem--;
      }
      sz = rem;
    }
    for (int i = 0; i < n; i++) {
      cout << res[i] << ' ';
    }
    cout << '\n';
  }
}