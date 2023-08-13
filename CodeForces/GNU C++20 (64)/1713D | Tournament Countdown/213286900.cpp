#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(1 << n);
    iota(a.begin(), a.end(), 1);
    while (a.size() >= 4) {
      vector<int> next;
      int tmp;
      for (int i = 0; i < (int)a.size(); i += 4) {
        cout << "? " << a[i] << ' ' << a[i + 2] << endl;
        cin >> tmp;
        int l, r;
        if (tmp == 0) {
          l = 1;
          r = 3;
        } else if (tmp == 1) {
          l = 0;
          r = 3;
        } else {
          l = 1;
          r = 2;
        }
        cout << "? " << a[i + l] << ' ' << a[i + r] << endl;
        cin >> tmp;
        if (tmp == 1) {
          next.push_back(a[i + l]);
        } else if (tmp == 2) {
          next.push_back(a[i + r]);
        }
      }
      a = next;
    }
    if (a.size() == 2) {
      cout << "? " << a[0] << ' ' << a[1] << endl;
      int x;
      cin >> x;
      cout << "! " << (x == 1 ? a[0] : a[1]) << endl;
    } else {
      cout << "! " << a[0] << endl;
    }
  }
}