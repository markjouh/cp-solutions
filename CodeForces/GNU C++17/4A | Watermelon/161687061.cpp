// Problem: A. Watermelon
// Contest: Codeforces - Codeforces Beta Round #4 (Div. 2 Only)
// URL: https://codeforces.com/problemset/problem/4/A
// Memory Limit: 64 MB
// Time Limit: 1000 ms
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int w;
  cin >> w;
  cout << (w > 2 && w % 2 == 0 ? "YES\n" : "NO\n");
}