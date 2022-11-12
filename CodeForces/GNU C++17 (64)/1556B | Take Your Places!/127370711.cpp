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
  vector<int> even, odd;
  int bal = 0;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   (x % 2 ? odd : even).push_back(i);
   bal += (x % 2 ? 1 : -1);
  }
  if (abs(bal) > 1) {
   cout << -1 << '\n';
   continue;
  }
  vector<int> move = (even.size() < odd.size() ? even : odd);
  int ans = INT_MAX;
  for (int rep = even.size() != odd.size(); rep <= 1; rep++) {
   int cur = 0, pos = rep;
   for (int x : move) {
    cur += abs(pos - x);
    pos += 2;
   }
   ans = min(ans, cur);
  }
  cout << ans << '\n';
 }
}