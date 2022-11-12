#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cout << (x <= k);
      if (x <= k) {
        k -= x;
      }
    }
    cout << '\n';
  }
}