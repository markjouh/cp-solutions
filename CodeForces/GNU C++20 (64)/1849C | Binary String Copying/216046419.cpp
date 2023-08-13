#include "bits/stdc++.h"
using namespace std;
 
#ifdef ONLINE_JUDGE
#define debug if (false)
#else
#define debug if (true)
#endif
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
 
void solve() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<int> nxt(n + 1, n), lst(n + 1, -1);
  for (int i = n - 1; i >= 0; i--) {
    nxt[i] = s[i] == '1' ? i : nxt[i + 1];
  }
  for (int i = 0; i < n; i++) {
    lst[i + 1] = s[i] == '0' ? i : lst[i];
  }
  set<pii> st;
  while (m--) {
    int l, r;
    cin >> l >> r;
    
    l--;
    l = nxt[l];
    r = lst[r];
    if (l < r) {
      st.insert({l, r});
    } else {
      st.insert({-1, -1});
    }
  }
  cout << sz(st) << '\n';
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}