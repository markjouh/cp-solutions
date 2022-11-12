#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x; cin >> n >> x;
    vector<int> deg(n+1);
    for (int i = 0; i < n-1; i++) {
      int u, v; cin >> u >> v;
      deg[u]++;
      deg[v]++;
    }
    cout << (deg[x] <= 1 || (n - 3) % 2 ? "Ayush\n" : "Ashish\n") << '\n';
  }
}