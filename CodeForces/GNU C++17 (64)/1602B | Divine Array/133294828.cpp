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
  vector<int> nums(n);
  for (int& x : nums) {
   cin >> x;
  }
  vector<vector<int>> stages(1);
  stages[0] = nums;
  bool go = true;
  while (go) {
   go = false;
   vector<int> count(2001), cur(n);
   for (int x : stages.back()) {
    count[x]++;
   }
   for (int i = 0; i < n; ++i) {
    cur[i] = count[stages.back()[i]];
   }
   if (cur != stages.back()) {
    stages.push_back(cur);
    go = true;
   }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
   int x, k;
   cin >> x >> k;
   cout << stages[min(k, (int)stages.size() - 1)][x - 1] << '\n';
  }
 }
}