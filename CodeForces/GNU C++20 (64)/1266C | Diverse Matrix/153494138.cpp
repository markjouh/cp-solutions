#include <bits/stdc++.h>
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= a; i--)
#define each(a, b) for (auto &a : b)
#define rep(a) FOR(_, 0, a)
 
using namespace std;
 
void solve() {
  int n;
  cin >> n;
  vector<int> ch(n);
  rep(n - 1) {
    int p;
    cin >> p;
    ch[p - 1]++;
  }
  ch.erase(remove(all(ch), 0), ch.end());
  sort(all(ch), greater<int>());
  
  int ans = sz(ch) + 1;
  
  priority_queue<int> q;
  FOR(i, 0, sz(ch)) {
    ch[i] -= sz(ch) - i;
    if (ch[i] > 0) {
      q.push(ch[i]);
    }
  }
  
  int rem = 0;
  while (sz(q) && q.top() > rem) {
    // By default, we have to add 1 second for the root vertex. However, if the spread operation is the only one
    // needed on our last second, we can use the remaining inject operation on the root, saving one.
    if (q.top() == ++rem) {
      break;
    }
    q.push(q.top() - 1);
    q.pop();
    ans++;
  }
  cout << ans << '\n';
}
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  rep(tc) {
    solve();
  }
}