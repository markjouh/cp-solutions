#include <bits/stdc++.h>
using namespace std;
 
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
    int m;
    cin >> m;
    int id = 0;
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      id = (id + x) % n;
    }
    cout << a[id] << '\n';
  }
}