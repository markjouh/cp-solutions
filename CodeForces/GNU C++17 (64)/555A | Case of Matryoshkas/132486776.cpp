#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
bool permutation(vector<int> v) {
 for (int i = 0; i < v.size(); i++) {
  if (v[i] != i + 1) {
   return false;
  }
 }
 return true;
}
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n, k;
 cin >> n >> k;
 int ans = -1;
 for (int i = 0; i < k; i++) {
  int len;
  cin >> len;
  vector<int> chain(len);
  for (int& x : chain) {
   cin >> x;
  }
  while (!permutation(chain)) {
   chain.pop_back();
   ans++;
   ans += !chain.empty();
  }
  if (chain.size()) {
   ans++;
  }
 }
 cout << ans << '\n';
}