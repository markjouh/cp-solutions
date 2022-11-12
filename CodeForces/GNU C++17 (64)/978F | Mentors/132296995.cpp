#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n, k;
 cin >> n >> k;
 vector<int> skill(n), sorted;
 for (int& x : skill) {
  cin >> x;
 }
 sorted = skill;
 sort(sorted.begin(), sorted.end());
 map<int, int> mp;
 for (int i = 0; i < n; i++) {
  if (!mp.count(sorted[i])) {
   mp[sorted[i]] = i;
  }
 }
 vector<int> res(n);
 for (int i = 0; i < n; i++) {
  res[i] = mp[skill[i]];
 }
 for (int i = 0; i < k; i++) {
  int x, y;
  cin >> x >> y;
  x--;
  y--;
  if (skill[x] > skill[y]) {
   res[x]--;
  }
  if (skill[y] > skill[x]) {
   res[y]--;
  }
 }
 for (int x : res) {
  cout << max(0, x) << ' ';
 }
 cout << '\n';
}