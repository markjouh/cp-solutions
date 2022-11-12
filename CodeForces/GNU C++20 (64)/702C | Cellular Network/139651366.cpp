// cloudcloud
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> cities(n), towers(m);
  for (int &x : cities) {
    cin >> x;
  }
  for (int &x : towers) {
    cin >> x;
  }
  int id = 0, mx = 0;
  for (int x : cities) {
    while (id < m - 1 && abs(x - towers[id + 1]) <= abs(x - towers[id])) {
      id++;
    }
    mx = max(mx, abs(x - towers[id]));
  }
  cout << mx << '\n';
}