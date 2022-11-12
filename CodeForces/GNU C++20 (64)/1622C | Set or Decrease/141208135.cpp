#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    long long n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    long long need = accumulate(a.begin(), a.end(), 0ll)-k;
    if (need <= 0) {
      cout << 0 << '\n';
      continue;
    }
    sort(a.rbegin(), a.rend());
    for (int &x : a) {
      x -= a[n-1];
    }
    long long csum = 0, ans = need;
    for (int i = 0; i < n-1; i++) {
      csum += a[i];
      ans = min(ans, i+1 + max(0ll, (need-csum+i+1)/(i+2)));
    }
    cout << ans << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/