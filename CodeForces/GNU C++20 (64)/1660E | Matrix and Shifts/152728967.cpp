#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
template<class T> using vt = vector<T>;
 
#define fi first
#define se second
#define pb push_back
#define pp pop_back
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vt<vt<int>> table(n, vt<int>(n));
    vt<int> ct(2);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < n; j++) {
        table[i][j] = s[j]-'0';
        ct[table[i][j]]++;
      }
    }
    int best = 0;
    for (int i = 0; i < n; i++) {
      int cur = 0;
      for (int j = 0; j < n; j++) {
        cur += table[(0+j)%n][(i+j)%n];
      }
      best = max(best, cur);
      cur = 0;
      for (int j = 0; j < n; j++) {
        cur += table[(i+j)%n][(0+j)%n];
      }
      best = max(best, cur);
    }
    cout << n-best + ct[1]-best << '\n';
  }
}