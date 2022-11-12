#include <bits/stdc++.h>
 
using namespace std;
 
const int M = 1e9 + 7;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 
 int N = 2e5 + 1;
 vector<int> len(N), ct(10);
 len[0] = 1;
 ct[0] = ct[1] = 1;
 for (int i = 1; i <= N; i++) {
  int add = ct[9];
  ct[9] = 0;
  for (int j = 8; j >= 0; j--) {
   ct[j + 1] = ct[j];
   ct[j] = 0;
  }
  ct[0] = add % M;
  ct[1] = (ct[1] + add) % M;
  len[i] = (len[i - 1] + add) % M;
 }
 
 int T;
 cin >> T;
 while (T--) {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  while (n > 0) {
   if (m >= 10 - n % 10) {
    ans = (ans + len[m - (10 - n % 10)]) % M;
   }
   ans = (ans + 1) % M;
   n /= 10;
  }
  cout << ans << '\n';
 }
}