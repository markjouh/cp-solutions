#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  sort(a.begin(), a.end(), greater<int>());
  int res = 0;
  for (int i = 0; i < k; i++) {
   res += a[i + k] / a[i];
  }
  for (int i = k * 2; i < n; i++) {
   res += a[i];
  }
  cout << res << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/