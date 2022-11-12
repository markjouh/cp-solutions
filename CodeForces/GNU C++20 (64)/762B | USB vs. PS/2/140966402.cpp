#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int a, b, c, m;
 cin >> a >> b >> c >> m;
 vector<pair<int, string>> mice(m);
 for (int i = 0; i < m; i++) {
  int x;
  string s;
  cin >> x >> s;
  mice[i] = {x, s};
 }
 sort(all(mice));
 int ct = 0;
 ll cost = 0;
 for (auto [f, s] : mice) {
  if (s == "USB") {
   if (!a && !c) continue;
   (a ? a : c)--;
   ct++;
   cost += f;
  }
  if (s == "PS/2") {
   if (!b && !c) continue;
   (b ? b : c)--;
   ct++;
   cost += f;
  }
 }
 cout << ct << ' ' << cost << '\n';
}