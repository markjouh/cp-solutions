#include "bits/stdc++.h"
 
using namespace std;
 
#define int int64_t
 
// gameplan:
// 1) stall until the mimic changes forms for the first time, the cnt that increased is the mimic's current type T (max 2 moves)
// 2) delete all elements not of type T, the remaining set will consist of real objects of type T and the mimic (1 move)
// 3) stall until the mimic changes forms again, after which it will be the only element of type != T (max 1 move)
// 4) return the answer (1 move)
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), cnt_a(10);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt_a[a[i]]++;
    }
    vector<int> old = a, cnt_o = cnt_a;
    
    while (cnt_a == cnt_o) {
      cout << "- 0" << endl;
      fill(cnt_a.begin(), cnt_a.end(), 0);
      for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt_a[a[i]]++;
      }
    }
 
    int type = -1;
    for (int i = 1; i <= 9; i++) {
      if (cnt_a[i] > cnt_o[i]) {
        type = i;
        break;
      }
    }
    assert(type != -1);
 
    cout << "- " << n - cnt_a[type] << ' ';
    for (int i = 0; i < n; i++) {
      if (a[i] != type) {
        cout << i + 1 << ' ';
      }
    }
    cout << endl;
    n = cnt_a[type];
    a.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
 
    while (count(a.begin(), a.end(), type) == n) {
      cout << "- 0" << endl;
      for (int i = 0; i < n; i++) {
        cin >> a[i];
      }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != type) {
        ans = i;
        break;
      }
    }
    cout << "! " << ans + 1 << endl;
  }
}