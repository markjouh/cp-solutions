#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,a,b) for (int i = a; i < b; i++)
#define per(i,a,b) for (int i = b-1; i >= a; i--)
#define ea(x,a) for (auto &x : a)
using ll = long long;
template<class T> using vt = vector<T>;
#define fi first
#define se second
#define pb push_back
#define pp pop_back
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
int mod = 998244353;
 
ll mmul(ll a, ll b) {
  return ((a%mod)*(b%mod))%mod;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vt<pair<int,int>> op(q);
    ea(p,op)
      cin >> p.fi >> p.se;
    reverse(all(op));
    ll ans = 1;
    vt<bool> row(n+1), col(m+1);
    int rowct = 0, colct = 0;
    ea(p,op) {
      if ((!row[p.fi] || !col[p.se]) && rowct < n && colct < m) {
        ans = mmul(ans,k);
        rowct += !row[p.fi];
        row[p.fi] = true;
        colct += !col[p.se];
        col[p.se] = true;
      }
    }
    cout << ans << '\n';
  }
}