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
#define srt(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define pb push_back
#define pp pop_back
#define eb emplace_back
#define ft front()
#define bk back()
#define f first
#define s second
 
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
 
const int INF = 1e9;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  vvi pos(26);
  F0R(i,n)
    pos[s[i]-'a'].pb(i);
  // Minimum position we can assign to each prefix, etc.
  vi lo(m), hi(m+1);
  FOR(i,0,m) {
    int c = t[i]-'a';
    lo[i] = pos[c][upb(pos[c], (i ? lo[i-1] : -1))];
  }
  hi[m] = 1e9;
  ROF(i,0,m) {
    int c = t[i]-'a';
    hi[i] = pos[c][lwb(pos[c], (i < m-1 ? hi[i+1] : INF))-1];
  }
  int ans = 0;
  FOR(i,0,m-1)
    ckmax(ans, hi[i+1]-lo[i]);
  cout << ans << '\n';
}
 
/*
  Read the problem statement very carefully
  Think twice before implementing!
*/