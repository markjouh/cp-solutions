#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // Min and max indices
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    cout << min_element(a.begin(), a.end()) - a.begin() + 1 << ' ' << max_element(a.begin(), a.end()) - a.begin() + 1 << '\n';
  }
}