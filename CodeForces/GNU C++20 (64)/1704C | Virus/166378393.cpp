#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
 
#define FOR(i, a, n) for (int i = 0; i < (int)n; i++)
#define ROF(i, a, n) for (int i = 0; i < (int)n; i++)
#define fi first
#define se second
 
const int MAXN = 1e5;
 
int n, m;
int a[MAXN], ok[MAXN];
 
int msub(int a, int b) {
  if (a == b) {
    return n;
  }
  return (((a - b) % n) + n) % n;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    FOR(i, 0, m) {
      cin >> a[i];
    }
    sort(a, a + m);
    FOR(i, 0, m) {
      ok[i] = msub(a[(i + 1) % m], a[i]) - 1;
    }
    sort(ok, ok + m, greater<int>());
    int save = 0;
    int infect = 0;
    FOR(i, 0, m) {
      int now = max(0, ok[i] - 2 * infect);
      if (now > 0) {
        save += max(1, now - 1);
      }
      infect += 2;
    }
    cout << n - save << '\n';
  }
}