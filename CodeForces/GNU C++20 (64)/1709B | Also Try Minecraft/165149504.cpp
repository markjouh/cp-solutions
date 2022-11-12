#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<long long> pref(n);
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + max(0, h[i - 1] - h[i]);
  }
  vector<long long> suf(n);
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = suf[i + 1] + max(0, h[i + 1] - h[i]);
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    if (l < r) {
      cout << pref[r] - pref[l] << '\n';
    } else {
      swap(l, r);
      cout << suf[l] - suf[r] << '\n';
    }
  }
}