#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

const vector<int> dy{-1, 0, 1, 0}, dx{0, 1, 0, -1};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<vector<bool>> pass(n, vector<bool>(m));
  vector<vector<bool>> rest(n, vector<bool>(m));
  pass[1][1] = true;
  rest[1][1] = true;
  queue<pii> q;
  q.emplace(1, 1);
  while (sz(q)) {
    auto [y, x] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int y2 = y, x2 = x;
      while (s[y2 + dy[i]][x2 + dx[i]] == '.') {
        y2 += dy[i];
        x2 += dx[i];
        pass[y2][x2] = true;
      }
      if (!rest[y2][x2]) {
        rest[y2][x2] = true;
        q.emplace(y2, x2);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans += pass[i][j];
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


