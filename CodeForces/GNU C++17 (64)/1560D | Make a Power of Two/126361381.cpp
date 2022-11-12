#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 vector<string> a;
 ll cur = 1;
 while (cur <= 1e16) {
  a.push_back(to_string(cur));
  cur *= 2;
 }
 auto sz = [&](string s) {
  return (int)s.size();
 };
 int tc;
 cin >> tc;
 while (tc--) {
  string s;
  cin >> s;
  int mn = INT_MAX;
  string best;
  for (string x : a) {
   int cnt = 0;
   for (int i = 0; i < s.size(); i++) {
    if (i - cnt >= x.size()) {
     break;
    }
    if (s[i] != x[i - cnt]) {
     cnt++;
    }
   }
   cnt += abs(sz(s) - sz(x) - cnt);
   mn = min(mn, cnt);
  }
  cout << mn << '\n';
 }
}