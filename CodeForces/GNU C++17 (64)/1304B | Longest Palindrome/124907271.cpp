#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.tie(0);
 cin.sync_with_stdio(0);
 int n, m;
 cin >> n >> m;
 set<string> st;
 vector<string> a;
 string mid;
 auto rev = [&](string s) {
  reverse(s.begin(), s.end());
  return s;
 };
 auto pal = [&](string s) {
  return rev(s) == s;
 };
 for (int i = 0; i < n; i++) {
  string s;
  cin >> s;
  if (st.count(rev(s))) {
   a.push_back(rev(s));
   st.erase(rev(s));
  } else {
   st.insert(s);
  }
 }
 for (string s : st) {
  if (pal(s) && s.size() > mid.size()) {
   mid = s;
  }
 }
 string res = mid;
 for (string s : a) {
  res = s + res + rev(s);
 }
 cout << res.size() << '\n' << res << '\n';
}