#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double;
using str = string;
 
using pi = pair<int, int>;
using pl = pair<ll, ll>;
 
template<class T> using vt = vector<T>; 
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
#define eb emplace_back
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
 
/*
  Count the number of times each bit appears in the range l..r and in the array a
  If a bit x appears the same number of times in both, bit x is 0, otherwise 1
*/
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  rep(tc) {
    int l, r;
    cin >> l >> r;
    int n = r-l+1;
    vi a(n);
    each(x,a)
      cin >> x;
    vi bits(17), abits(17);
    FOR(i,l,r+1)
      F0R(bit,17)
        bits[bit] += (i>>bit)&1;
    each(x,a)
      F0R(bit,17)
        abits[bit] += (x>>bit)&1;
    int ans = 0;
    F0R(i,17)
      if (bits[i] != abits[i])
        ans += pow(2,i);
    cout << ans << '\n';
  }
}
 
/*
  Read the problem statement very carefully
  Think twice before implementing!
*/