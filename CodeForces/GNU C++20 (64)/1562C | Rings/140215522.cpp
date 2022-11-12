#include <bits/stdc++.h>
using namespace std;
 
void solve() {
 int n;
 string s;
 cin >> n >> s;
 if (s == string(n, '0') || s == string(n, '1')) {
  cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << '\n';
  return;
 }
 for (int i = 0; i + n / 2 < n; i++) {
  if (s[i] == '0') {
   cout << i + 1 << ' ' << i + n / 2 + 1 << ' ' << i + 2 << ' ' << i + n / 2 + 1 << '\n';
   return;
  }
 }
 for (int i = n / 2; i < n; i++) {
  if (s[i] == '0') {
   cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << '\n';
   return;
  }
 }
}
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int T;
 cin >> T;
 while (T--) {
  solve();
 }
}
 
/*
 Think before implementing!
*/