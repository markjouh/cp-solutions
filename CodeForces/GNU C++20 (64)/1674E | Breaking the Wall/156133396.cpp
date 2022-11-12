#include <bits/stdc++.h>
using namespace std;
 
#define SZ(x) (int)size(x)
#define ALL(x) begin(x), end(x)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  int ans = 1e9;
  // Case of two walls with distance > 1
  int lo = 1e9, lo2 = 1e9;
  for (int x : a) {
    lo2 = min(lo2, (x+1)/2);
    if (lo2 < lo) {
      swap(lo, lo2);
    }
  }
  ans = min(ans, lo+lo2);
  // Case of two walls with distance 1
  for (int i = 0; i < n-2; i++) {
    int mn = min(a[i], a[i+2]), mx = max(a[i], a[i+2]);
    ans = min(ans, mn + (mx-mn+1)/2);
  }
  // Case of two adjacent walls
  for (int i = 0; i < n-1; i++) {
    int x = max(a[i], a[i+1]), y = min(a[i], a[i+1]);
    if (y*2 <= x) {
      ans = min(ans, (x+1)/2);
    } else {
      ans = min(ans, x-y + (2*(y-x+y)+2)/3);
    }
  }
  cout << ans << '\n';
}