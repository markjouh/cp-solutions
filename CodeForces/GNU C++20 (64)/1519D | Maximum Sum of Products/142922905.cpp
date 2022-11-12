#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<i64> a(n), b(n);
  FOR(i, n) {
    cin >> a[i];
  }
  FOR(i, n) {
    cin >> b[i];
  }
  i64 orig = 0;
  FOR(i, n) {
    orig += a[i]*b[i];
  }
  i64 ans = orig;
  FOR(i, n) {
    i64 cur = orig;
    FOR(j, min(i+1, n-i)) {
      cur += (a[i-j]*b[i+j] + a[i+j]*b[i-j]) - (a[i-j]*b[i-j] + a[i+j]*b[i+j]);
      ans = max(ans, cur);
    }
  }
  FOR(i, n-1) {
    i64 cur = orig;
    for (int j = 0; i-j >= 0 && i+j+1 < n; j++) {
      cur += (a[i-j]*b[i+j+1] + a[i+j+1]*b[i-j]) - (a[i-j]*b[i-j] + a[i+j+1]*b[i+j+1]);
      ans = max(ans, cur);
    }
  }
  cout << ans << '\n';
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/