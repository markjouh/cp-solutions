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
    vector<int> a(n), ct(n+1);
    for (int &x : a) {
      cin >> x;
      ct[x]++;
    }
    sort(a.begin(), a.end());
    vector<long long> res(n+1, -1);
    stack<int> stk;
    long long sum = 0;
    for (int i = 0; i <= n; i++) {
      if (i > 0 && ct[i-1] == 0) {
        if (stk.empty()) {
          break;
        }
        int t = stk.top();
        stk.pop();
        sum += i-1-t;
      }
      res[i] = sum+ct[i];
      if (i > 0) {
        for (int j = 0; j < ct[i-1]-1; j++) {
          stk.push(i-1);
        }
      }
    }
    for (long long x : res) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/