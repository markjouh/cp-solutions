// Problem: A. Watermelon
// Contest: Codeforces - Codeforces Beta Round #4 (Div. 2 Only)
// URL: https://codeforces.com/problemset/problem/4/A
// Memory Limit: 64 MB
// Time Limit: 1000 ms
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define int int64_t
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int w;
  cin >> w;
  cout << (w > 2 && w % 2 == 0 ? "YES\n" : "NO\n");
}