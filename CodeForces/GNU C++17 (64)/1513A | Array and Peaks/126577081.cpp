#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, k;
  cin >> n >> k;
  if (k * 2 >= n) {
   cout << -1 << '\n';
   continue;
  }
  deque<int> vals(n);
  iota(vals.begin(), vals.end(), 1);
  vector<int> res;
  for (int i = 0; i < n; i++) {
   if (i % 2 && k > 0) {
    res.push_back(vals.back());
    vals.pop_back();
    k--;
   } else {
    res.push_back(vals.front());
    vals.pop_front();
   }
  }
  for (int x : res) {
   cout << x << ' ';
  }
  cout << '\n';
 }
}