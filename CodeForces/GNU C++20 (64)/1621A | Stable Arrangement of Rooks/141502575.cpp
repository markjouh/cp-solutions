#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    if (k > (n+1)/2) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j && (i+1)%2 == n%2 && k > 0) {
          cout << 'R';
          k--;
        } else {
          cout << '.';
        }
      }
      cout << '\n';
    }
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/