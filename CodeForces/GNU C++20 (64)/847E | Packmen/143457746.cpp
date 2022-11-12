#include <bits/stdc++.h>
using namespace std;
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  vector<int> pac, ast;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'P') {
      pac.push_back(i);
    }
    if (s[i] == '*') {
      ast.push_back(i);
    }
  }
  int psz = pac.size(), asz = ast.size();
  int l = 0, r = n * 2;
  while (l + 1 < r) {
    int mid = l + (r - l) / 2;
    int j = 0;
    for (int i = 0; i < psz; i++) {
      int ldist = max(0, pac[i] - ast[j]);
      while (j < asz && ast[j] < pac[i] && pac[i] - ast[j] <= mid) {
        j++;
      }
      while (j < asz && ast[j] > pac[i] && ldist + ast[j] - pac[i] + min(ldist, ast[j] - pac[i]) <= mid) {
        j++;
      }
    }
    (j == asz ? r : l) = mid;
  }
  cout << r << '\n';
}