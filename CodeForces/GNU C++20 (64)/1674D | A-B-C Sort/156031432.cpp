#include <bits/stdc++.h>
using namespace std;
 
#define SZ(x) (int)size(x)
#define ALL(x) begin(x), end(x)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    reverse(ALL(a));
    vector<int> c;
    if (n % 2) {
      c.push_back(a.back());
      a.pop_back();
    }
    while (SZ(a)) {
      c.push_back(min(a[SZ(a)-1], a[SZ(a)-2]));
      c.push_back(max(a[SZ(a)-1], a[SZ(a)-2]));
      a.pop_back();
      a.pop_back();
    }
    bool ok = true;
    for (int i = 1; i < n; i++) {
      ok &= c[i] >= c[i-1];
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}