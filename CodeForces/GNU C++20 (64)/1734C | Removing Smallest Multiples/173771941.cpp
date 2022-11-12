#include <bits/stdc++.h>
using namespace std;
 
// it is always optimal to remove elements in left to right order
// element x can be removed for cost k if all previous multiples of k were removed already (leaving it the smallest multiple of k)
 
constexpr int mxN = 1e6 + 1;
 
int k[mxN];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  string s;
  cin >> n >> s;
  fill(k, k + n + 1, 0);
  for (int i = n; i >= 1; i--) {
   for (int j = i; j <= n; j += i) {
    if (s[j - 1] == '1') {
     break;
    }
    k[j] = i;
   }
  }
  
  long long ans = 0;
  for (int i = 0; i < n; i++) {
   if (s[i] == '0') {
    ans += k[i + 1];
   }
  }
  cout << ans << '\n';
 }
}