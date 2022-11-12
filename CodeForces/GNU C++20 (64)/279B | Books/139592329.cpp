// cloudcloud
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, t;
  cin >> n >> t;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  long long sum = 0;
  int id = 0, res = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (sum > t) {
      sum -= a[id++];
    }
    res = max(res, i - id + 1);
  }
  cout << res << '\n';
}