#include <bits/stdc++.h>
using namespace std;
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define each(x, a) for (auto &x : a)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep1(i, n) for (int i = 1; i <= (int)n; i++)
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> a(n);
 each(x, a) {
  cin >> x;
 }
 int neg = 0;
 rep(i, n) {
  if (a[i] >= 0) {
   a[i] = -a[i] - 1;
  }
  neg ^= a[i] < 0;
 }
 if (neg) {
  int id = 0, mn = 1e9;
  rep(i, n) {
   if (a[i] < mn) {
    id = i;
    mn = a[i];
   }
  } 
  a[id] = -a[id] - 1;
 }
 each(x, a) {
  cout << x << ' ';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/