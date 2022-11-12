#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) > 1 || a + b > n - 2) {
   cout << -1 << '\n';
   continue;
  }
  vector<int> res;
  int lo = 1, hi = n;
  if (a >= b) {
   res.push_back(lo++);
   while (a > 0 || b > 0) {
    if (a > 0) {
     res.push_back(hi--);
     a--;
    }
    if (b > 0) {
     res.push_back(lo++);
     b--;
    }
   }
  } else {
   res.push_back(hi--);
   while (a > 0 || b > 0) {
    if (b > 0) {
     res.push_back(lo++);
     b--;
    }
    if (a > 0) {
     res.push_back(hi--);
     a--;
    }
   }
  }
  if (!res.empty() && res.back() == lo - 1) {
   for (int i = lo; i <= hi; i++) {
    res.push_back(i); 
   }
  } else {
   for (int i = hi; i >= lo; i--) {
    res.push_back(i);
   }
  }
  for (int x : res) {
   cout << x << ' ';
  }
  cout << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/