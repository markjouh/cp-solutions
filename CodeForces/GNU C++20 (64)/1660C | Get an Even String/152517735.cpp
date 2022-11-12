// cloudcloud
#include <bits/stdc++.h>
using namespace std;
 
// Trying out this big template
 
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpb = vector<vb>;
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
#define sz(a) (int)a.size()
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
    string s;
    cin >> s;
    vb seen(26);
    int ans = sz(s);
    F0R(i,(int)sz(s)) {
      if (seen[s[i]-'a']) {
        ans -= 2;
        fill(all(seen),false);
      } else {
        seen[s[i]-'a'] = true;
      }
    }
    cout << ans << '\n';
  }
}