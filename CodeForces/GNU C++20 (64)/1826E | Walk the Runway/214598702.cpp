// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")
 
#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int main() {
 cin.tie(0)->sync_with_stdio(0);
 cin.exceptions(cin.failbit);
 int m, n;
 cin >> m >> n;
 vi profit(n+1);
 rep(i, 1, n+1) {
  cin >> profit[i];
 }
 vector<vi> rating(m, vi(n+1));
 rep(i, 0, m) {
  rep(j, 1, n+1) {
   cin >> rating[i][j];
  }
 }
 vector<bitset<5001>> less(n+1);
 rep(i, 0, n+1) {
  less[i].set();
 }
 rep(i, 0, m) {
  vi ord(n+1);
  iota(all(ord), 0);
  sort(all(ord), [&](int a, int b) {
   return rating[i][a] > rating[i][b];
  });
  bitset<5001> cur;
  int k = 0;
  rep(j, 0, n+1) {
   while (k < j && rating[i][ord[k]] > rating[i][ord[j]]) {
    cur[ord[k]] = 1;
    k++;
   }
   less[ord[j]] &= cur;
  }
 }
 vi ord(n+1);
 iota(all(ord), 0);
 rep(i, 0, n) {
  rep(j, i+1, n+1) {
   if (less[ord[j]][ord[i]]) {
    swap(ord[i], ord[j]);
   }
  }
 }
 vector<ll> dp(n+1);
 rep(i, 1, n+1) {
  rep(j, 0, i) {
   int oi = ord[i];
   int oj = ord[j];
   if (less[oj][oi]) {
    dp[oi] = max(dp[oi], dp[oj] + profit[oi]);
   }
  }
 }
 cout << *max_element(all(dp)) << '\n';
}