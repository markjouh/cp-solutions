#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int w, h;
  cin >> w >> h;
  long long res = 0;
  for (int i = 0; i < 2; i++) {
   for (int j = 0; j < 2; j++) {
    int k;
    cin >> k;
    vector<int> a(k);
    for (int &x : a) {
     cin >> x;
    }
    res = max(res, 1ll * (a.back() - a.front()) * (i ? w : h));
   }
  }
  cout << res << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/