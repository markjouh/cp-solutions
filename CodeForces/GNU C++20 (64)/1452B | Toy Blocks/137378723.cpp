#include <bits/stdc++.h>
using namespace std;
 
int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    long long sum = 0;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      sum += x;
      mx = max(mx, x);
    }
    long long res = mx * (n - 1);
    if (res < sum) {
      res += (sum - res + n - 2) / (n - 1) * (n - 1);
    }
    cout << res - sum << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Try to think of ideas from past problems
  Check for edge cases, overflow, etc.
*/