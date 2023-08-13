#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
 
void solve() {
 int n;
 cin >> n;
 vector<int> e, e_ind;
 vector<int> o, o_ind;
 for (int i = 0; i < n; i++) {
  int x;
  cin >> x;
  if (x % 2) {
   o.push_back(x);
   o_ind.push_back(i);
  } else {
   e.push_back(x);
   e_ind.push_back(i);
  }
 }
 vector<int> res(n);
 sort(all(e));
 for (int i = 0; i < sz(e); i++) {
  res[e_ind[i]] = e[i];
 }
 sort(all(o));
 for (int i = 0; i < sz(o); i++) {
  res[o_ind[i]] = o[i];
 }
 bool ok = true;
 for (int i = 1; i < n; i++) {
  ok &= res[i] >= res[i - 1];
 }
 cout << (ok ? "YES\n" : "NO\n");
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