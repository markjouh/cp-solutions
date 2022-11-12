#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define REP(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = b - 1; i >= (int)a; i--)
#define PER(i, a) ROF(i, 0, a)
 
template<class T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
void subtr(vector<int> &a, vector<int> b) {
  int n = a.size(), m = b.size();
  // Long subtraction
  REP(i, m) {
    if (b[m - i - 1] > a[n - i - 1]) {
      a[n - i - 2]--;
      a[n - i - 1] += 10;
    }
    a[n - i - 1] -= b[m - i - 1];
  }
  // Remove leading zeroes
  reverse(a.begin(), a.end());
  while (!a.empty() && a.back() == 0) {
    a.pop_back();
  }
  reverse(a.begin(), a.end());
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin.exceptions(cin.failbit);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> d(n);
    REP(i, n) {
      d[i] = s[i] - '0';
    }
    if (d[0] == 9) {
      vector<int> res(n + 1, 1);
      subtr(res, d);
      REP(i, res.size()) {
        cout << res[i];
      }
      cout << '\n';
    } else {
      vector<int> res(n);
      REP(i, n / 2 + 1) {
        ckmax(res[i], 9 - d[i]);
        ckmax(res[n - i - 1], 9 - d[n - i - 1]);
      }
      REP(i, n) {
        cout << res[i];
      }
      cout << '\n';
    }
  }
}