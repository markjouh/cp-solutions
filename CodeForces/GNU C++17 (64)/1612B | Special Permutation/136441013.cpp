#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> perm(n - 2), res;
  int id = 0, cur = 1;
  while (id < n - 2) {
   if (cur != a && cur != b) {
    perm[id] = cur;
    ++id;
   }
   ++cur;
  }
  vector<int> l{a}, r{b};
  while (l.size() < n / 2 && perm.back() > a) {
   l.push_back(perm.back());
   perm.pop_back();
  }
  reverse(perm.begin(), perm.end());
  while (r.size() < n / 2 && perm.back() < b) {
   r.push_back(perm.back());
   perm.pop_back();
  }
  if (l.size() < n / 2 || r.size() < n / 2) {
   cout << -1 << '\n';
   continue;
  }
  for (int x : l) {
   cout << x << ' ';
  }
  for (int x : r) {
   cout << x << ' ';
  }
  cout << '\n';
 }
}