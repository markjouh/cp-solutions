#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> customers(n, vector<int>(3)), tmp;
    for (auto &v : customers) {
      for (int &x : v) {
        cin >> x;
      }
    }
    sort(customers.begin(), customers.end());
    for (int i = 1; i < n; i++) {
      if (customers[i][0] == customers[i - 1][0]) {
        customers[i - 1][0] = -1;
        customers[i][1] = max(customers[i][1], customers[i - 1][1]);
        customers[i][2] = min(customers[i][2], customers[i - 1][2]);
      }
    }
    for (auto v : customers) {
      if (v[0] != -1) {
        tmp.push_back(v);
      }
    }
    customers = tmp;
    customers.insert(customers.begin(), {0, m, m});
    n = customers.size();
    for (int i = n - 2; i >= 0; i--) {
      int interval = customers[i + 1][0] - customers[i][0];
      customers[i][1] = max(customers[i][1], customers[i + 1][1] - interval);
      customers[i][2] = min(customers[i][2], customers[i + 1][2] + interval);
    }
    bool ok = true;
    for (auto v : customers) {
      ok &= v[1] <= v[2];
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}