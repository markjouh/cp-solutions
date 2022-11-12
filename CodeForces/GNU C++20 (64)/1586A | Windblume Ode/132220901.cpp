#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
bool composite(int x) {
 for (int i = 2; i <= sqrt(x); i++) {
  if (x % i == 0) {
   return true;
  }
 }
 return false;
}
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> inscribed(n);
  int sum = 0;
  for (int& x : inscribed) {
   cin >> x;
   sum += x;
  }
  set<int> res;
  for (int i = 1; i <= n; i++) {
   res.insert(i);
  }
  if (!composite(sum)) {
   for (int i = 0; i < n; i++) {
    if (composite(sum - inscribed[i])) {
     res.erase(i + 1);
     break;
    }
   }
  }
  cout << res.size() << '\n';
  for (int x : res) {
   cout << x << ' ';
  }
  cout << '\n';
 }
}