#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int cnt = 0;
    queue<bool> q;
    for (int i = 0; i < k; i++) {
      if (a[i] >= a[i + 1] * 2) {
        cnt++;
        q.push(1);
      } else {
        q.push(0);
      }
    }
    int ans = 0;
    for (int i = k; i < n - 1; i++) {
      ans += cnt == 0;
      cnt -= q.front();
      q.pop();
      if (a[i] >= a[i + 1] * 2) {
        cnt++;
        q.push(1);
      } else {
        q.push(0);
      }
    }
    ans += cnt == 0;
    cout << ans << '\n';
  }
}