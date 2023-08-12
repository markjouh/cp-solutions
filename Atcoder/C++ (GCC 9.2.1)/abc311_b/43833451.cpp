#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

void solve() {
  int n, d;
  cin >> n >> d;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int cur = 0, ans = 0;
  for (int i = 0; i < d; i++) {
    bool ok = true;
    for (int j = 0; j < n; j++) {
      ok &= s[j][i] == 'o';
    }
    if (ok) {
      cur++;
      ckmax(ans, cur);
    } else {
      cur = 0;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  /* cin >> t; */
  while (t--) {
    #ifndef ONLINE_JUDGE
      cout << string(32, '_') << endl;
    #endif
    solve();
  }
  return 0;
}


