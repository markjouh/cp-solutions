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
    int l = 0, r = 1e5;
    while (l + 1 < r) {
      int mid = l + (r - l) / 2;
      int a = mid / 3, b = (mid + 2) / 3, c = mid - a - b;
      ((a * b + a * c + b * c) * 2 < n ? l : r) = mid;
    }
    cout << r << '\n';
  }
}