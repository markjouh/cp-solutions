#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n, k, m, t;
 cin >> n >> k >> m >> t; 
 k--;
 int len = n;
 while (t--) {
  int type, id;
  cin >> type >> id;
  if (type) {
   len++;
   k += --id <= k; 
  } else {
   if (k < id) {
    len = id;
   } else {
    len -= id;
    k -= id;
   }
  }
  cout << len << ' ' << k + 1 << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/