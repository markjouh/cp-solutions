#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
/*
  If a doesn't contain a 1, we can always make everything 0 by applying x = a[i] for each element n - 1..0
 
  Otherwise, we can make everything equal to 1 if there are no 0's or consecutive elements. This is because
  the set of the factors of x - 1 excluding 1 is equal to the set of numbers y such that x % y == 1.
 
  This is true because remainders here can be described as the result of subtracting a number from another number
  continually while keeping the result nonnegative. This means that all numbers y that can form x - 1 (x - 1's factors)
  represented as y * ((x - 1) / y), "subtracting" y ((x - 1) / y) times. 1 is excluded because it can also form x.
*/
 
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
    auto has = [&](int x) {
      return find(a.begin(), a.end(), x) != a.end();
    };
    sort(a.begin(), a.end());
    bool consecutive = false;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] + 1 == a[i + 1]) {
        consecutive = true;
        break;
      }
    }
    cout << (!has(1) || (!has(0) && !consecutive) ? "YES\n" : "NO\n");
  }
}