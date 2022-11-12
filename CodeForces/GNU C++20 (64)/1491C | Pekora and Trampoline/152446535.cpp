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
    vl a(n), ch(n+1);
    each(x,a) {
      cin >> x;
    }
    ll ans = 0;
    F0R(i,n) {
      // Make sure we have enough bounces on a[i] to reduce it to 1.
      int add = max(0ll,a[i]-ch[i]-1);
      ch[i] += add;
      ans += add;
 
      // Ignore all bounces over n-1.
      int rm = max(0ll, a[i]-n+i+1);
      a[i] -= rm;
      ch[i] -= rm;
 
      while (a[i] > 1 && ch[i] > 0) {
        ch[i+a[i]]++;
        a[i]--;
        ch[i]--;
      }
      ch[i+1] += ch[i];
    }
    cout << ans << '\n';
  }
}