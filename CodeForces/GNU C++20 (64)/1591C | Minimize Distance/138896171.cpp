#include <bits/stdc++.h>
using namespace std;
 
int last = 0;
 
long long dist(vector<int> loc, int k) {
 sort(loc.begin(), loc.end());
 int n = loc.size(), rem = 0;
 long long dist = 0;
 for (int i = n - 1; i >= 0; i--) {
  if (rem == 0) {
   dist += loc[i] * 2;
   last = max(last, loc[i]);
   rem = k;
  }
  rem--;
 }
 return dist;
}
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, k;
  cin >> n >> k;
  vector<int> pos, neg;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   (x < 0 ? neg : pos).push_back(abs(x));
  }
  last = 0;
  cout << dist(pos, k) + dist(neg, k) - last << '\n'; 
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 