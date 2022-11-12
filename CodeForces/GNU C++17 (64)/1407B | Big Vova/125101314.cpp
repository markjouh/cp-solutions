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
  for (int &x : a)  {
   cin >> x;
  }
  sort(a.begin(), a.end());
  vector<int> res = {a.back()};
  int div = a.back();
  a.pop_back();
  while (!a.empty()) {
   int best = 0, pos;
   for (int i = 0; i < a.size(); i++) {
    int g = gcd(a[i], div);
    if (g > best) {
     best = g;
     pos = i;
    }
   }
   div = best;
   res.push_back(a[pos]);
   a.erase(a.begin() + pos);
  }
  for (int x : res) {
   cout << x << ' ';
  }
  cout << '\n';
 }
}