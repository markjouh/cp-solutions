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
  auto unsorted = [&]() {
   for (int i = 1; i < a.size(); i++) {
    if (a[i] < a[i - 1]) {
     return true;
    }
   }
   return false;
  };
  int cnt = 0;
  while (unsorted()) {
   for (int i = cnt % 2; i < n; i += 2) {
    if (i < n - 1 && a[i] > a[i + 1]) {
     swap(a[i], a[i + 1]);
    }
   }
   cnt++;
  }
  cout << cnt << '\n';
 }
}