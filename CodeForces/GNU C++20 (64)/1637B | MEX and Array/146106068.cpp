#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define rb pop_back
#define bg begin()
#define ed end()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    // Divide all subsegments into individual elements
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += i * (n + 1 - i);
    }
    // Get the number of segments that contain a 0
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        pre[i + 1]++;
      }
    }
    for (int i = 1; i <= n; i++) {
      pre[i] += pre[i - 1];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        ans += pre[i] - pre[j];
      }
    }
    cout << ans << '\n';
  }
}