#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...)
#endif
 
template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | ";debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &x : grid) {
      for (auto &y : x) {
        cin >> y;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int cur = grid[i][j];
        for (int y = i + 1, x = j + 1; y < n && x < m; y++, x++) {
          cur += grid[y][x];
        }
        for (int y = i - 1, x = j + 1; y >= 0 && x < m; y--, x++) {
          cur += grid[y][x];
        }
        for (int y = i - 1, x = j - 1; y >= 0 && x >= 0; y--, x--) {
          cur += grid[y][x];
        }
        for (int y = i + 1, x = j - 1; y < n && x >= 0; y++, x--) {
          cur += grid[y][x];
        }
        ans = max(ans, cur);
      }
    }
    cout << ans << '\n';
  }
}