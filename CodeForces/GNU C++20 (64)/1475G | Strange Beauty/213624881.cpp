// Problem: G. Strange Beauty
// Contest: Codeforces - Codeforces Round 697 (Div. 3)
// URL: https://codeforces.com/contest/1475/problem/G
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include "bits/stdc++.h"
 
using namespace std;
 
// #define int long long
 
// let's fix our final set of numbers
// all larger numbers' prime factors must be a superset of the smaller ones' prime factors
 
// an O(n^2) dp solution would be:
// sort the array
// dp[i][j] = [prefix of a][greatest number] = most elements kept
 
// this is probably too slow
// but the time limit is 5s
// are there any optimizations we can make?
// what redundant states can we get rid of?
 
// all transitions are in the form
// a[i] % x == 0, dp[x] -> new_dp[a[i]]
// for each a[i], we can simply iterate over the divisors
 
// actually we can get rid of [i] entirely, since dp[x] -> dp[a[i]] only overlaps in the case x = a[i]
// just make sure to handle that first
 
// time complexity: O(N * sqrt(N))
 
const int N = 2e5;
int dp[N + 1];
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    memset(dp, 0, sizeof dp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      dp[a[i]]++;
      for (int j = 1; j * j <= a[i]; j++) {
        if (a[i] % j == 0 && j != a[i]) {
          dp[a[i]] = max(dp[a[i]], dp[j] + 1);
          if (j != 1) {
            dp[a[i]] = max(dp[a[i]], dp[a[i] / j] + 1);
          }
        }
      }
      ans = max(ans, dp[a[i]]);
    }
    cout << n - ans << '\n';
  }
}