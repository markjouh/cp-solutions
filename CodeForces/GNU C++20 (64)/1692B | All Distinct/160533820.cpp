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
    vector<int> cnt(1e4 + 1);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    int rem = 0;
    for (int i = 1; i <= 1e4; i++) {
      if (cnt[i] > 0) {
        rem += cnt[i] - 1;
      }
    }
    cout << n - rem - (rem % 2) << '\n';
  }
}