#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int q, x;
 cin >> q >> x;
 vector<int> cnt(x);
 int cur = 0;
 while (q--) {
  int y;
  cin >> y;
  ++cnt[y % x];
  while (cnt[cur % x] > 0) {
   --cnt[cur % x];
   ++cur;
  }
  cout << cur << '\n';
 }
}