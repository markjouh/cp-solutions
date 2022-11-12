#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n, k;
 cin >> n >> k;
 vector<int> alice, bob, pairs;
 for (int i = 0; i < n; ++i) {
  int t;
  bool a, b;
  cin >> t >> a >> b;
  if (a && b) {
   pairs.push_back(t);
  } else if (a) {
   alice.push_back(t);
  } else if (b) {
   bob.push_back(t);
  }
 }
 sort(alice.begin(), alice.end());
 sort(bob.begin(), bob.end());
 for (int i = 0; i < min(alice.size(), bob.size()); ++i)  {
  pairs.push_back(alice[i] + bob[i]);
 }
 if (pairs.size() < k) {
  cout << -1 << '\n';
  return 0;
 }
 sort(pairs.begin(), pairs.end());
 cout << accumulate(pairs.begin(), pairs.begin() + k, 0) << '\n';
}