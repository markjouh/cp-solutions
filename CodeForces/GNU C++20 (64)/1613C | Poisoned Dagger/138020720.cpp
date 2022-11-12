#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  long long n, h;
  cin >> n >> h;
  vector<int> time(n);
  for (int &x : time) {
   cin >> x;
  }
  vector<long long> bound(n);
  for (int i = 0; i < n; ++i) {
   bound[i] = time[i + 1] - time[i];
  }
  bound[n - 1] = h;
  long long l = 0, r = h;
  while (l + 1 < r) {
   long long mid = l + (r - l) / 2;
   long long sum = 0;
   for (long long x : bound) {
    sum += min(mid, x);
   }
   if (sum >= h) {
    r = mid;
   } else {
    l = mid;
   }
  }
  cout << r << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 