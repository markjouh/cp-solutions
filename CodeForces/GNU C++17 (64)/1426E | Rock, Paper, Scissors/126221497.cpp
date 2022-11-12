#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> a(3), b(3);
 for (int &x : a) {
  cin >> x;
 }
 for (int &x : b) {
  cin >> x;
 }
 // wins
 int mx = 0;
 mx += min(a[0], b[1]);
 mx += min(a[1], b[2]);
 mx += min(a[2], b[0]);
 // losses
 vector<pair<int, int>> moves = {{0, 0}, {1, 1}, {2, 2}, {0, 2}, {1, 0}, {2, 1}};
 int mn = INT_MAX;
 do {
  vector<int> tmpa = a, tmpb = b;
  for (auto [x, y] : moves) {
   int rem = min(tmpa[x], tmpb[y]);
   tmpa[x] -= rem;
   tmpb[y] -= rem;
  }
  mn = min(mn, tmpa[0] + tmpa[1] + tmpa[2]);
 } while (next_permutation(moves.begin(), moves.end()));
 cout << mn << ' ' << mx << '\n';
}