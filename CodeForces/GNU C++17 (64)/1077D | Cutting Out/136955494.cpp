#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n, k;
 cin >> n >> k;
 vector<int> nums(2e5 + 1);
 for (int i = 0; i < n; ++i) {
  int x;
  cin >> x;
  ++nums[x];
 }
 int l = 0, r = n + 1;
 vector<int> res;
 while (l + 1 < r) {
  int mid = l + (r - l) / 2;
  vector<int> cur;
  for (int i = 1; i <= 2e5; ++i) {
   for (int j = 0; j < nums[i] / mid; ++j) {
    cur.push_back(i);
   }
  }
  if (cur.size() >= k) {
   l = mid;
   res = cur;
  } else {
   r = mid;
  }
 }
 for (int i = 0; i < k; ++i) {
  cout << res[i] << ' ';
 }
}