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
  ch.push_back(1);
  
  int ans = sz(ch);
  
  priority_queue<int> q;
  FOR(i, 0, sz(ch)) {
    ch[i] -= sz(ch) - i;
    if (ch[i] > 0) {
      q.push(ch[i]);
    }
  }
  
  int rem = 0;
  while (sz(q) && q.top() > rem) {
    q.push(q.top() - 1);
    q.pop();
    rem++;
  }
  ans += rem;
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