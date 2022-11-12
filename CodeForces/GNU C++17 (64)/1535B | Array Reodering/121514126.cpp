#include <bits/stdc++.h>
using namespace std;
 
int arr[2000], res[2000];
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  deque<int> q;
  for (int i = 0; i < n; i++) {
   int a;
   cin >> a;
   if (a % 2) {
    q.push_back(a);
   } else {
    q.push_front(a);
   }
  }
  int ans = 0;
  for (int i = 0; i < q.size(); i++) {
   for (int j = i + 1; j < q.size(); j++) {
    if (__gcd(q[i], q[j] * 2) > 1) {
     ans++;
    }
   }
  }
  cout << ans << '\n';
 }
}