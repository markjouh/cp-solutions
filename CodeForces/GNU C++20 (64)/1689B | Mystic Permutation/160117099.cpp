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
 
using ll = long long;
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= (int)a; i--)
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
int p[1000], q[1000];
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    set<pair<int, int>> st;
    FOR(i, 0, n) {
      cin >> p[i];
      st.insert({p[i], i});
    }
    if (n == 1) {
      cout << -1 << '\n';
      continue;
    }
    // We can always create a mystic permutation with any n distinct elements where n > 1, so just greedily take first n - 2 and handle the last 2 manually
    FOR(i, 0, n - 2) {
      auto bg = st.begin();
      if ((*bg).second == i) {
        advance(bg, 1);
      }
      cout << (*bg).first << ' ';
      st.erase(bg);
    }
    auto a = st.begin(), b = st.begin();
    advance(b, 1);
    if ((*a).second == n - 2 || (*b).second == n - 1) {
      swap(a, b);
    }
    cout << (*a).first << ' ' << (*b).first << '\n';
  }
}