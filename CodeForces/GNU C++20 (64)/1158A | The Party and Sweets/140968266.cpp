#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n, m;
 cin >> n >> m;
 vector<int> give(n), get(m);
 for (int &x : give) {
  cin >> x;
 }
 for (int &x : get) {
  cin >> x;
 }
 sort(all(give));
 sort(all(get));
 if (get[0] < give[n - 1]) {
  cout << -1 << '\n';
  return 0;
 }
 ll ans = accumulate(all(give), 0ll) * m;
 for (int i = m - 1; i >= 1; i--) {
  ans += get[i] - give[n - 1];
 }
 if (get[0] > give[n - 1]) {
  ans += get[0] - give[n - 2];
 }
 cout << ans << '\n';
}