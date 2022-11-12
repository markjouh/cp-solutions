#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int q;
 cin >> q;
 set<pair<int, int>> st[2];
 int cnt = 0;
 while (q--) {
  int t;
  cin >> t;
  if (t == 1) {
   int m;
   cin >> m;
   ++cnt;
   m = -m;
   st[0].insert({cnt, m});
   st[1].insert({m, cnt});
  } else {
   auto [a, b] = *st[t - 2].begin();
   cout << max(a, b) << ' ';
   st[t - 2].erase({a, b});
   st[(t - 2) ^ 1].erase({b, a});
  }
 }
}