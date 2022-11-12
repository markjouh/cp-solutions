#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (long long &x : a) {
   cin >> x;
  }
  auto get = [&](int id) {
   long long G = 0;
   for (int i = id; i < n; i += 2) {
    G = gcd(G, a[i]);
   }
   return G;
  };
  bool ok = true;
  long long G = get(0);
  for (int i = 1; i < n; i += 2) {
   ok &= a[i] % G != 0;
  }
  if (ok) {
   cout << G << '\n';
   continue;
  }
  ok = true;
  G = get(1);
  for (int i = 0; i < n; i += 2) {
   ok &= a[i] % G != 0;
  }
  if (ok) {
   cout << G << '\n';
   continue;
  }
  cout << 0 << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/