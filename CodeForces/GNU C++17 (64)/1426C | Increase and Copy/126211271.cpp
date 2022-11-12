#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  ll add = 0, ans = LLONG_MAX;
  while (add + (n + add) / (add + 1) <= ans) {
   ans = add + (n + add) / (add + 1);
   add++;
  }
  cout << ans - 1 << '\n';
 }
}