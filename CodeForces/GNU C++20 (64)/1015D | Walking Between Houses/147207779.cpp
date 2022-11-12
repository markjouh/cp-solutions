#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 ll n, k, s; cin >> n >> k >> s;
 if (k > s || k < s / (n - 1) + (s % (n - 1) != 0)) {
  cout << "NO\n";
  return 0;
 }
 cout << "YES\n";
 ll pos = 1;
 for (int i = 0; i < k; i++) {
  ll d = s / k + (i < s % k);
  i % 2 ? pos -= d : pos += d;
  cout << pos << ' ';
 }
 cout << '\n';
 }