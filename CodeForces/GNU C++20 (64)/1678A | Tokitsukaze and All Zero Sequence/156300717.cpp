#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
#define sz(x) int(size(x))
#define all(x) begin(x), end(x)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> cnt(101);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    if (cnt[0]) {
      cout << n-cnt[0] << '\n';
      continue;
    }
    bool rep = false;
    for (int i = 0; i <= 100; i++) {
      rep |= cnt[i] > 1;
    }
    cout << (rep ? n : n+1) << '\n';
  }
}