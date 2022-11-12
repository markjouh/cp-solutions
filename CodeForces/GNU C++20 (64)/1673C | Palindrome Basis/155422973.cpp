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
 
const int mod = 1e9+7;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vi pal;
  FOR(i,1,4e4) {
    string s = to_string(i);
    bool ok = true;
    F0R(j,sz(s)/2)
      ok &= s[j] == s[sz(s)-j-1];
    if (ok)
      pal.pb(i);
  }
  int n = sz(pal);
 
  int target = 4e4;
  vvi dp(n+1,vi(target+1,0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-pal[i-1];
      if (left >= 0)
        (dp[i][j] += dp[i][left]) %= mod;
    }
  }
 
  int tc;
  cin >> tc;
  rep(tc) {
    int tgt;
    cin >> tgt;
    cout << dp[n][tgt] << endl;
  } 
}
 
/*
  Read the problem statement very carefully
  Think twice before implementing!
*/