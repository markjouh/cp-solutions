#include <bits/stdc++.h>
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, m;
  cin >> n >> m;
  vector<int> nums(n);
  for (int &x : nums) {
   cin >> x;
  }
  int id = -1;
  for (int i = 0; i < n; ++i) {
   if (nums[i] != i + 1) {
    id = i;
   }
  }
  double res = 0;
  for (int i = 0; i < m; ++i) {
   int len;
   double prob;
   cin >> len >> prob;
   if (len > id) {
    res = res + prob - res * prob;
   }
  }
  cout << fixed << (id == -1 ? 1.0 : res) << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 
 