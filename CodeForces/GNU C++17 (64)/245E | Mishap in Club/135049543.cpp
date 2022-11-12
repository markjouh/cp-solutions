#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
template <class T, class S> inline bool ckmax(T& a, const S& b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool ckmin(T& a, const S& b) { return (a > b ? a = b, 1 : 0); }
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 string s;
 cin >> s;
 int bal = 0, mn = 0, mx = 0;
 for (char c : s) {
  bal += (c == '+' ? 1 : -1);
  ckmin(mn, bal);
  ckmax(mx, bal);
 }
 cout << mx - mn << '\n';
}