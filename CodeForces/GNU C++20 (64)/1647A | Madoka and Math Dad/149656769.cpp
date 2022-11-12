#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
void solve() {
  int n;
  cin >> n;
  string s1, s2;
  int sum1 = 0, sum2 = 0;
  for (int i = 0; sum1 != n && sum2 != n; i++) {
    s1 += (i % 2 ? '1' : '2');
    sum1 += (i % 2 ? 1 : 2);
    s2 += (i % 2 ? '2' : '1');
    sum2 += (i % 2 ? 2 : 1);
    if (sum1 == n) {
      cout << s1 << '\n';
      return;
    }
    if (sum2 == n) {
      cout << s2 << '\n';
      return;
    }
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}