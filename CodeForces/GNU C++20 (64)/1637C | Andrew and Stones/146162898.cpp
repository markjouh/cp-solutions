#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define rb pop_back
#define bg begin()
#define ed end()
 
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
    bool ok = false;
    ll ans = 0;
    for (int i = 1; i < n - 1; i++) {
      ans += (a[i] + 1) / 2;
      ok |= a[i] > 1;
    }
    cout << (ok && !(n == 3 && a[1] % 2) ? ans : -1) << '\n';
  }
}