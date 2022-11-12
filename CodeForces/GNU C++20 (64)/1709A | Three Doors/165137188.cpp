#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int x;
    cin >> x;
    x--;
    vector<int> a(3);
    for (int i = 0; i < 3; i++) {
      cin >> a[i];
    }
    cout << (a[x] != 0 && a[a[x] - 1] != 0 ? "YES\n" : "NO\n");
  }
}