#include <bits/stdc++.h>
using namespace std;

int w[10000], s[10000], v[10000], ord[10000];
long long dp[20001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> s[i] >> v[i];
  }
  iota(ord, ord + n, 0);
  sort(ord, ord + n, [](int i, int j) {
    return w[i] + s[i] < w[j] + s[j];
  });
  for (int i = 0; i < n; i++) {
    int id = ord[i];
    for (int j = s[id]; j >= 0; j--) {
      dp[j + w[id]] = max(dp[j + w[id]], dp[j] + v[id]);
    }
  }
  cout << *max_element(dp, dp + 20001);
}