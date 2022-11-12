#include <bits/stdc++.h>
using namespace std;
 
map<string, int> m;
 
inline int get(string a, string b) {
 if (!m.count(a) || !m.count(b)) {
  return 2e9;
 }
 return m[a] + m[b];
}
 
int main() {
 int n;
 cin >> n;
 for (int i = 0; i < n; i++) {
  int a;
  string s;
  cin >> a >> s;
  sort(s.begin(), s.end());
  m[s] = (m.count(s) ? min(m[s], a) : a);
 }
 int ans = 2e9;
 if (m.count("ABC")) ans = m["ABC"];
 if (m.count("A") && m.count("B") && m.count("C")) ans = min(ans, m["A"] + m["B"] + m["C"]);
 ans = min(ans, get("AB", "C"));
 ans = min(ans, get("AC", "B"));
 ans = min(ans, get("BC", "A"));
 ans = min(ans, get("AB", "BC"));
 ans = min(ans, get("AC", "AB"));
 ans = min(ans, get("AC", "BC"));
 if (ans == 2e9) ans = -1;
 cout << ans << '\n';
}