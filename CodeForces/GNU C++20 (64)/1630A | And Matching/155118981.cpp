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
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  rep(tc) {
    int n, k;
    cin >> n >> k;
 
    int mx = log2(n);
    vi cmpl(n);
    F0R(i,n)
      F0R(bit,mx)
        if (!((i>>bit)&1))
          cmpl[i] += pow(2,bit);
 
    if (k == 0) {
      F0R(i,n/2)
        cout << i << ' ' << cmpl[i] << '\n';
    } else if (k == n-1) {
      if (n == 4) {
        cout << -1 << '\n';
        continue;
      }
      // Pair n-1 with n-2, pair 1 with n-3, pair 0 with 2
      cout << n-1 << ' ' << n-2 << '\n';
      cout << 1 << ' ' << n-3 << '\n';
      cout << 0 << ' ' << 2 << '\n';
      FOR(i,3,3+(n-6)/2)
        cout << i << ' ' << cmpl[i] << '\n';
    } else {
      // Pair k with n-1, pair cmpl[k] with 0
      cout << k << ' ' << n-1 << '\n';
      cout << cmpl[k] << ' ' << 0 << '\n';
      FOR(i,1,1+(n-2)/2)
        if (i != k && i != cmpl[k])
          cout << i << ' ' << cmpl[i] << '\n';
    }
  }
}
 
/*
  Read the problem statement very carefully
  Think twice before implementing!
*/