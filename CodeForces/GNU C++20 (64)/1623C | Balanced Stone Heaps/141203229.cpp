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
  vector<int> piles(n);
  for (int &x : piles) {
   cin >> x;
  }
  int l = 0, r = *max_element(piles.begin(), piles.end())+1;
  while (l+1 < r) {
   int mid = l+(r-l)/2;
   vector<int> p = piles;
   for (int i = n-1; i >= 2; i--) {
    int sb = min(piles[i], max(0, p[i]-mid))/3;
    p[i] -= sb*3;
    p[i-1] += sb;
    p[i-2] += sb*2;
   }
   (*min_element(p.begin(), p.end()) >= mid ? l : r) = mid;
  }
  cout << l << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Think before implementing!
*/