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
    ll n;
    cin >> n;
    if (n < 4 || n % 2) {
      cout << -1 << '\n';
    } else {
      cout << (n + 5) / 6 << ' ' << n / 4 << '\n';
    }
  }
}