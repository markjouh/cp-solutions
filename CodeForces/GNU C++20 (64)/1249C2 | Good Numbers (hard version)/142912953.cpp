#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
 
typedef __int128_t i128;
 
ostream& operator<<(ostream& os, __int128 x) {
    string s;
    while (x) {
      s += '0'+x%10;
      x /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}
 
i128 exp128(i128 base, int exp) {
  i128 res = 1;
  while (exp) {
    if (exp%2 == 1){
      res = res*base;
    }
    exp >>= 1;
    base = base*base;
  }
  return res;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    ll n, nc;
    cin >> n;
    nc = n;
    vector<int> ter;
    while (nc > 0) {
      ter.push_back(nc%3);
      nc /= 3;
    }
    int m = ter.size();
    ter.push_back(0);
    FOR(i, m) {
      if (ter[i] > 1) {
        ter[i] = 0;
        ter[i+1]++;
      }
    }
    i128 ans = 0;
    FOR(i, m+1) {
      if (ter[i]) {
        i128 p = exp128(3, i);
        ans += p;
      } 
    }
    FOR(i, m+1) {
      i128 p = exp128(3, i);
      if (ter[i] && ans-p >= n) {
        ter[i] = 0;
        ans -= p;
      }
    }
    cout << ans << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/