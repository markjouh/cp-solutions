#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> ans(32768, 1e9);
  ans[0] = 0;
  for (int i = 1; i < 32768; i++) {
    for (int j = 0; j <= 32768 - i; j++) {
      int bit = 0;
      for (; ((i + j) >> bit) > 0; bit++) {
        if (((i + j) >> bit) & 1) {
          break;
        }
      }
      ans[i] = min(ans[i], 15 - bit + j);
    }
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cout << ans[x] << ' ';
  }
}