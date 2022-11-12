#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 int balance = 0;
 for (int i = 0; i < n; i++) {
  int x;
  cin >> x;
  if (x % 2 == 0) {
   cout << x / 2 << '\n';
  } else {
   if (balance < 0) {
    if (x < 0) {
     cout << x / 2 << '\n';
    } else {
     cout << (x + 1) / 2 << '\n';
    }
    balance++;
   } else {
    if (x < 0) {
     cout << (x - 1) / 2 << '\n';
    } else {
     cout << x / 2 << '\n';
    }
    balance--;
   }
  }
 }
}