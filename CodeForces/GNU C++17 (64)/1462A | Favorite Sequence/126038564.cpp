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
  deque<int> q(n);
  for (int &x : q) {
   cin >> x;
  }
  vector<int> res;
  while (q.size()) {
   res.push_back(q.front());
   q.pop_front();
   if (q.size()) {
    res.push_back(q.back());
    q.pop_back();
   }
  }
  for (int x : res) {
   cout << x << ' ';
  }
  cout << '\n';
 }
}