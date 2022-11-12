#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
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
  unordered_set<int> gift;
  for (int x : a) {
   gift.insert(x);
  }
  vector<int> free;
  for (int i = 1; i <= n; i++) {
   if (!gift.count(i)) {
    free.push_back(i);
   }
  }
  int cnt = 0;
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
   if (gift.count(a[i])) {
    cnt++;
    res[i] = a[i];
    gift.erase(a[i]);
   } else {
    res[i] = free.back();
    free.pop_back();
   }
  }
  for (int i = 0; i < n; i++) {
   if (res[i] == i + 1) {
    for (int j = 0; j < n; j++) {
     if (i != j && a[i] == a[j]) {
      swap(res[i], res[j]);
     }
    }
   }
  }
  cout << cnt << '\n';
  for (int x : res) {
   cout << x << ' ';
  }
  cout << '\n';
 }
}