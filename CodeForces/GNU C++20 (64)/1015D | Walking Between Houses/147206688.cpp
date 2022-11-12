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
 vector<ll> moves(k, s / k);
 for (int i = 0; i < s % k; i++) {
  moves[i]++;
 }
 bool dir = 0;
 ll pos = 1;
 for (int x : moves) {
  dir ^= 1;
  dir ? pos += x : pos -= x;
  cout << pos << ' ';
 }
 cout << '\n';
 }