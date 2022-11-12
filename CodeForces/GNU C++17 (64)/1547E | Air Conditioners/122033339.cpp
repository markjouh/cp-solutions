#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  vector<long long> pos(k), temp(k), ac(n, INT_MAX), l(n), r(n);
  for (int i = 0; i < k; i++) {
   cin >> pos[i];
  }
  for (int i = 0; i < k; i++) {
   cin >> temp[i];
  }
  for (int i = 0; i < k; i++) {
   ac[pos[i] - 1] = temp[i];
  }
  long long cur = INT_MAX;
  for (int i = 0; i < n; i++) {
   cur = min(cur + 1, ac[i]);
   l[i] = cur;
  }
  cur = INT_MAX;
  for (int i = n - 1; i >= 0; i--) {
   cur = min(cur + 1, ac[i]);
   r[i] = cur;
  }
  for (int i = 0; i < n; i++) {
   cout << min(l[i], r[i]) << ' ';
  }
  cout << '\n';
 }
}