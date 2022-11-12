#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double;
using str = string;
 
using pi = pair<int, int>;
using pl = pair<ll, ll>;
 
template<class T>
using vt = vector<T>; 
using vb = vt<bool>;
using vi = vt<int>;
using vl = vt<ll>;
using vs = vt<str>;
using vpi = vt<pi>;
using vpl = vt<pl>;
using vvb = vt<vb>;
using vvi = vt<vi>;
using vvl = vt<vl>;
 
#define sz(x) int((x).size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend() 
#define rsz resize
#define ins insert
#define acc accumulate
#define pb push_back
#define rb pop_back
#define fi first
#define se second
 
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(vt<T> &a, const T &b) { return int(lb(all(a), b) - a.begin()); }
template<class T> int upb(vt<T> &a, const T &b) { return int(ub(all(a), b) - a.begin()); }
 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto &a : x)
 
#define ckmin(a,b) a = min(a,b)
#define ckmax(a,b) a = max(a,b)
 
const int mod = 1e9+7;
 
ll madd(ll &a, ll b) {
  return (a+b)%mod;
}
 
ll msub(ll a, ll b) {
  return (((a-b)%mod)+mod)%mod;
}
 
ll mmul(ll a, ll b) {
  return ((a%mod)*(b%mod))%mod;
}
 
ll mpow(ll base, ll exp) {
  ll res = 1;
  while (exp) {
    if (exp%2 == 1)
      res = (res*base)%mod;
    exp >>= 1;
    base = (base*base)%mod;
  }
  return res;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vi a(n);
  each(x,a) cin >> x;
  sort(all(a));
  ll ans = 0;
  F0R(i,n-1) {
    // non empty subsets that contain this difference
    ll sets = 0;
    sets = madd(sets,msub(mpow(2,n),n+1));
    sets = msub(sets,msub(mpow(2,i+1),i+2));
    sets = msub(sets,msub(mpow(2,n-i-1),n-i));
    ans = madd(ans,mmul((a[i+1]-a[i]),sets));
  }
  cout << ans << '\n';
}
 
/*
  Read the problem statement very carefully 
  Think twice before implementing!
*/