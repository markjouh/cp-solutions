#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
// we get the smallest prime divisor under 100, map it to a color, and set to res
 
int main() {
 cin.sync_with_stdio(false);
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
  vector<bool> prime(101, true);
  for (int i = 2; i * i <= 100; i++) {
   if (prime[i]) {
    for (int j = i * i; j <= 100; j += i) {
     prime[j] = false;
    }
   }
  }
  vector<int> res(n);
  int cnt = 0;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
   int x;
   for (int j = 1; j <= 100; j++) {
    if (prime[j] && gcd(a[i], j) >= 2) {
     x = j;
     break;
    }
   }
   if (!mp.count(x)) {
    cnt++;
    mp[x] = cnt;
   }
   res[i] = mp[x];
  }
  cout << cnt << '\n';
  for (int x : res) {
   cout << x << ' ';
  }
  cout << '\n';
 }
}