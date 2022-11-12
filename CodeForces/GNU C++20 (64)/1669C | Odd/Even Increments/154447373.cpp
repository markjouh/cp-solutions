#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
bool cnt[2][2];
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    memset(cnt, false, sizeof cnt);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[i % 2][x % 2] = true;
    }
    cout << (cnt[0][0] + cnt[0][1] == 1 && cnt[1][0] + cnt[1][1] == 1 ? "YES\n" : "NO\n");
  }
}