#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  string res;
  for (int i = 0; i < k; i++) {
    res += 'a'+i;
    for (int j = i+1; j < k; j++) {
      res += 'a'+i;
      res += 'a'+j;
    }
  }
  while (sz(res) < n) {
    res += res;
  }
  res.resize(n);
  cout << res << '\n';
}