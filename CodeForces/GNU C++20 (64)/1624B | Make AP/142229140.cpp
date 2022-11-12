#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b, c;
    cin >> a >> b >> c;
    bool ok = false;
    ok |= (b+b-a) > 0 && (b+b-a)%c == 0;
    ok |= (b-(c-b)) > 0 && (b-(c-b))%a == 0;
    ok |= (a+c)%2 == 0 && (a+c)/2%b == 0;
    ok |= a == b && a % c == 0;
    ok |= a == c && a % b == 0;
    ok |= b == c && b % a == 0;
    cout << (ok ? "YES" : "NO") << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/
 