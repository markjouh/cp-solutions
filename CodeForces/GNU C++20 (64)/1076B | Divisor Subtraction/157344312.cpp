#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rep1(i, n) for (int i = 1; i <= int(n); i++)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  // If prime, ans = 1
  bool prime = true;
  for (ll i = 2; i * i <= n; i++) {
    prime &= n % i != 0;
  }
  if (prime) {
    cout << 1 << '\n';
    return 0;
  }
  // If n can't be expressed as 2 * m for any integer m, apply one operation and it will
  bool add = 0;
  if (n % 2) {
    add = 1;
    for (ll i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
        n -= i;
        break;
      }
    }
  }
  // n = 2 * m, m will be decremented on each step until it becomes 0
  cout << n / 2 + add << '\n';
}