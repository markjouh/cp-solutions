#include <bits/stdc++.h>
using namespace std;
 
int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
   long long n, k;
   cin >> n >> k;
   long long ct = 1, ans = 0;
   while (ct < k) {
    ct += min(ct, k);
    ++ans;
   }
   ans += (n - ct + k - 1) / k;
   cout << ans << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Try to think of ideas from past problems
  Check for edge cases, overflow, etc.
*/