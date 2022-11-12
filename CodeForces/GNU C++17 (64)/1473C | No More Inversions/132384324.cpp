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
  vector<int> res(k);
  iota(res.begin(), res.end(), 1);
  reverse(res.begin() + k * 2 - n - 1, res.end());
  for (int x : res) {
   cout << x << ' ';
  }
  cout << '\n';
 }
}