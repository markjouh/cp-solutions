#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
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
  vector<int> res;
  bool flag = true;
  for (int i = 0; i < n; i++) {
   res.push_back(i + 1);
   if (flag && a[i] == 0 && a[i + 1] == 1) {
    res.push_back(n + 1);
    flag = false;
   }
  }
  if (flag && a[0] == 1) {
   res.insert(res.begin(), n + 1);
  } else if (flag && a[n - 1] == 0) {
   res.push_back(n + 1);
  }
  for (int x : res) {
   cout << x << ' ';
  }
  cout << '\n';
 }
}