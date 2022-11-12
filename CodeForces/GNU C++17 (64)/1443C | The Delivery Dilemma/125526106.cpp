#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n * 2; i++) {
   cin >> (i < n ? a[i].first : a[i - n].second);
  }
  sort(a.begin(), a.end());
  vector<ll> su(n + 1);
  for (int i = n - 1; i >= 0; i--) {
   su[i] = su[i + 1] + a[i].second;
  }
  ll ans = su[0];
  for (int i = 0; i < n; i++) {
   ans = min(ans, max((ll)a[i].first, su[i + 1]));
  }
  cout << ans << '\n';
 }
}