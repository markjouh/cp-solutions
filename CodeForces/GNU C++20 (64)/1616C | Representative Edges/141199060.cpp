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
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    int best = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        int cur = 0, diff = a[j]-a[i], dist = j-i, g = gcd(diff, dist);
        diff /= g;
        dist /= g;
        for (int k = 0; k < n; k++) {
          cur += (k-i) % dist == 0 && a[k]-a[i] == diff*(k-i)/dist;
        }
        best = max(best, cur);
      }
    }
    cout << n-best << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think before implementing!
*/
 