#include <bits/stdc++.h>
using namespace std;
 
long long gdiv(long long x, long long y) {
 return (x + y - 1) / y;
}
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  long long n, w;
  cin >> n >> w;
  vector<pair<int, int>> weights(n);
  for (int i = 0; i < n; i++) {
   cin >> weights[i].first;
   weights[i].second = i + 1;
  }
  sort(weights.rbegin(), weights.rend());
  long long cur = w;
  vector<int> pos;
  for (int i = 0; i < n; i++) {
   if (weights[i].first <= cur) {
    cur -= weights[i].first;
    pos.push_back(weights[i].second);
   }
  }
  cur = w - cur;
  if (cur >= gdiv(w, 2) && cur <= w) {
   cout << pos.size() << '\n';
   for (int x : pos) cout << x << ' ';
   cout << '\n';
  } else {
   cout << -1 << '\n';
  }
 }
}