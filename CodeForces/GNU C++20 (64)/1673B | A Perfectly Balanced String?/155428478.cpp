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
    string s;
    cin >> s;
    vi cnt(26);
    each(c,s)
      cnt[c-'a']++;
    vvi pos(26);
    F0R(i,sz(s))
      pos[s[i]-'a'].pb(i);
    bool ok = true;
    F0R(i,26) {
      if (sz(pos[i]) < 2)
        continue;
      F0R(j,sz(pos[i])-1) {
        vi ccnt(26);
        FOR(k,pos[i][j]+1,pos[i][j+1])
          ccnt[s[k]-'a']++;
        F0R(k,26)
          if (cnt[k] > 0 && k != i)
            ok &= ccnt[k] > 0;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}
 
/*
  Read the problem statement very carefully
  Think twice before implementing!
*/