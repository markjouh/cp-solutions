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
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  int dep = 0;
  queue<int> q;
  q.push(0);
  int id = 1;
  while (id < n) {
   q.push(q.front() + 1);
   id++;
   while (a[id] > a[id - 1] && id < n) {
    q.push(q.front() + 1);
    id++;
   }
   dep = max(dep, q.front() + 1);
   q.pop();
  }
  cout << dep << '\n';
 } 
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 