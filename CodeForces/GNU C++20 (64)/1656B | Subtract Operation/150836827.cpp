#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
/*
  When we apply an operation, it cancels out all previous ones.
  For example, if the first operation was performed on x, all
  other elements would be in the form a[i] - x. If we performed
  another operation on y - x, all other elements would receive
  -y + x, cancelling out the x, making all other elements be in
  the form a[i] - y.
 
  Because of this, there is a solution where there are two numbers
  with difference k. We can call the larger and smaller ones i and j.
  We can just perform the operation on all other numbers, then on
  a[j]. The last number will be a[i] - a[j], which will be equal to k.
*/
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      st.insert(x);
    }
    bool ok = false;
    for (int x : st) {
      ok |= st.count(x + k);
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}