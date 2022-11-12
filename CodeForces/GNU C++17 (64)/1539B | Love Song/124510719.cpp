#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  string s;
  cin >> n >> q >> s;
  char last = ' ';
  vector<int> pre(n + 1);
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + (int)(s[i] - 'a') + 1;
    last = s[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    int x = pre[r] - pre[l - 1];
    cout << x << '\n';
  }
}