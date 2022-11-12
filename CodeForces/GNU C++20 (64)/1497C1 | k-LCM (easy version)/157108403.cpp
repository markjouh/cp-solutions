#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rep1(i, n) for (int i = 1; i <= int(n); i++)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); 
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    if (n % 2) {
      cout << 1 << ' ' << n / 2 << ' ' << n / 2 << '\n';
    } else if (n % 4 == 0) {
      cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << '\n';
    } else {
      cout << 2 << ' ' << (n - 2) / 2 << ' ' << (n - 2) / 2 << '\n';
    }
  }
}