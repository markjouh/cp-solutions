#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int l = 2, r = n - 3;
    while (l + 1 < r) {
      int mid = l + (r - l) / 2;
      (n - mid < (mid - 1) * 2 ? r : l) = mid;
    }
    int a = (n - r + 1) / 2, b = (n - r) / 2;
    if (a == b) {
      a++;
      b--;
    }
    cout << a << ' ' << r << ' ' << b << '\n';
  }
}