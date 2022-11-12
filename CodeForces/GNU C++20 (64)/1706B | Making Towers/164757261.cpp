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
    int n;
    cin >> n;
    vector<int> last(n, -1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      c--;
      if (last[c] == -1 || (i - last[c]) % 2) {
        ans[c]++;
      }
      last[c] = i;
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}