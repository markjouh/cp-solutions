// cloudcloud
#include <bits/stdc++.h>
using namespace std;
 
// Trying out this big template
 
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vvi = vector<vi>;
using vvl = vector<vl>;
 
#define fi first
#define se second
#define ft front()
#define bk back()
#define bg begin()
#define ed end()
#define rbg rbegin()
#define red rend()
#define all(a) a.bg, a.ed
#define rall(a) a.rbg, a.red
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(x,a) for (auto &x : a)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vi a(n);
    each(x,a) {
      cin >> x;
    }
    sort(all(a));
    bool ok = true;
    FOR(i,0,n) {
      if (a[i] == 1) {
        continue;
      }
      ok &= a[i] < a[n-1] || ((i > 0 && a[i]-a[i-1] < 2) || (i < n-1 && a[i+1]-a[i] < 2));
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}