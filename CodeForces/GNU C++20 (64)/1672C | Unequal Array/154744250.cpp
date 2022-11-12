#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int MXN = 2e5;
int a[MXN];
 
int cost(int x) {
  if (x <= 2)
    return 0;
  if (x == 3)
    return 1;
  else
    return x - 3;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector<int> p;
    for (int i = 0; i < n - 1; i++)
      if (a[i] == a[i + 1]) {
        p.push_back(i);
        p.push_back(i + 1);
      }
    int m = p.size();
    if (m)
      cout << cost(p.back() - p.front() + 1) << '\n';
    else
      cout << 0 << '\n';
  }
}