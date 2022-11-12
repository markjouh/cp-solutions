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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
 
    if (n == 1) {
      bool prime = true;
      for (int i = 2; i * i <= a[0]; i++) {
        prime &= a[0] % i != 0;
      }
      cout << (prime ? 1ll * a[0] * a[0] : -1) << '\n';
      continue;
    }
 
    sort(a.begin(), a.end());
    long long m = 1ll * a[0] * a[n - 1];
    vector<int> factors;
    for (int i = 2; 1ll * i * i <= m; i++) {
      if (m % i == 0) {
        factors.push_back(i);
        if (i * i != m) {
          factors.push_back(m / i);
        }
      }
    }
    sort(factors.begin(), factors.end());
    cout << (a == factors ? m : -1) << '\n';
    DEBUG(a);
    DEBUG(factors);
  }
}