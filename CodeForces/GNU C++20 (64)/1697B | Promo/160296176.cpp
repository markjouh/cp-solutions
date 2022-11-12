#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<long long> suf(n);
  for (int i = 0; i < n; i++) {
    cin >> suf[i];
  }
  sort(suf.begin(), suf.end());
  suf.push_back(0);
  for (int i = n - 2; i >= 0; i--) {
    suf[i] += suf[i + 1];
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << suf[n - x] - suf[n - x + y] << '\n';
  }
}