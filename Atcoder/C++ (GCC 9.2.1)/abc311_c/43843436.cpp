#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  vector<int> to(n);
  vector<int> in(n);
  for (int i = 0; i < n; i++) {
    cin >> to[i];
    to[i]--;
    in[to[i]]++;
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (in[i] == 0) {
      q.push(i);
    }
  }
  while (sz(q)) {
    int u = q.front();
    q.pop();
    if (--in[to[u]] == 0) {
      q.push(to[u]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (in[i] == 1) {
      vector<int> ans;
      int u = i;
      do {
        ans.push_back(u);
        u = to[u];
      } while (u != i);
      cout << sz(ans) << '\n';
      for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] + 1 << ' ';
      }
      cout << '\n';
      return;
    }
  }
  cout << 0 << '\n';
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


