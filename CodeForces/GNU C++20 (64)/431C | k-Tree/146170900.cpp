#include <bits/stdc++.h>
using namespace std;
 
const int M = 1e9 + 7;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int N, K, D;
 cin >> N >> K >> D;
 
 int dp[N+1][2]{};
 dp[0][0] = 1;
 
 for (int i = 0; i < N; i++) {
  for (int j = 0; j < 2; j++) {
   for (int k = 1; k <= K; k++) {
    if (i+k <= N) {
     dp[i+k][j || k >= D] = (dp[i+k][j || k >= D] + dp[i][j]) % M;
    }
   }
  }
 }
 
 cout << dp[N][1] << '\n';
}