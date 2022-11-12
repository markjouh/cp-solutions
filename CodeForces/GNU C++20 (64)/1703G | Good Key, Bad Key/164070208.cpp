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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<long long> pref(n), suf(n);
    pref[0] = a[0] - k;
    for (int i = 1; i < n; i++) {
      pref[i] = pref[i - 1] + a[i] - k;
    }
    for (int i = n - 1; i >= 0; i--) {
      suf[i] += a[i];
      int j = i;
      while (a[i] > 0 && j >= 0) {
        int quo = (a[i] + 1) / 2;
        a[i] -= quo;
        suf[j] -= quo;
        j--;
      }
      if (i + 1 < n) {
        suf[i] += suf[i + 1];
      }
    }
    long long ans = max(pref[n - 1], suf[0]);
    for (int i = 0; i + 1 < n; i++) {
      ans = max(ans, pref[i] + suf[i + 1]);
    }
    cout << ans << '\n';
  }
}