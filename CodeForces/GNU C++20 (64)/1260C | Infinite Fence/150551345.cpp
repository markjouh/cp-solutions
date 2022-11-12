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
    int a, b, k;
    cin >> a >> b >> k;
    if (a > b) {
      swap(a, b);
    }
    int g = gcd(a, b);
    a /= g;
    b /= g;
    cout << ((b + a - 2) / a < k ? "OBEY\n" : "REBEL\n");
  }
}