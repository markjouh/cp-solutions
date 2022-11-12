#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
      (s[i] == '0' ? cnt0 : cnt1)++;
    }
    long long ans = 1ll * cnt0 * cnt1;
 
    s += '*';
    int streak = 1;
    for (int i = 1; i < n + 1; i++) {
      if (s[i] == s[i - 1]) {
        streak++;
      } else {
        ans = max(ans, 1ll * streak * streak);
        streak = 1;
      }
    }
 
    cout << ans << '\n';
  }
}