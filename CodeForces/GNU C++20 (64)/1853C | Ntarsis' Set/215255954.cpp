#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
 
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] != 1) {
    cout << 1 << '\n';
    return;
  }
  vector<int> activate(n);
  activate[0] = 1;
  ll pos = 1;
  for (int i = 1; i < n; i++) {
    /* activate[i] = activate[i - 1] + (a[i] - a[i - 1]) / i; */
    ll steps = (a[i] - pos - 1) / i;
    pos += steps * i;
    activate[i] = activate[i - 1] + steps;
  }
  /* for (int i = 0; i < n; i++) { */
  /*   cerr << activate[i] << ' '; */
  /* } */
  /* cerr << '\n'; */
  vector<ll> days(k + 1);
  for (int i = 0; i < n; i++) {
    if (activate[i] <= k) {
      days[activate[i]]++;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= k; j++) {
      days[j] += days[j - 1];
    }
  }
  cout << days[k] + 1 << '\n';
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
 
 