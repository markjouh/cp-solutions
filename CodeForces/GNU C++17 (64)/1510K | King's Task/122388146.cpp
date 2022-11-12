#include <bits/stdc++.h>
using namespace std;
 
void op1(vector<int> &v) {
 for (int i = 0; i < v.size(); i += 2) {
  swap(v[i], v[i + 1]);
 }
}
 
void op2(vector<int> &v) {
 for (int i = 0; i < v.size() / 2; i++) {
  swap(v[i], v[i + v.size() / 2]);
 }
}
 
bool vsorted(vector<int> v) {
 for (int i = 1; i < v.size(); i++) {
  if (v[i] < v[i - 1]) {
   return false;
  }
 }
 return true;
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 vector<int> v(n * 2), sorted;
 for (int &x : v) {
  cin >> x;
 }
 if (vsorted(v)) {
  cout << 0 << '\n';
  return 0;
 }
 vector<int> a = v, b = v;
 for (int i = 0; i < n; i++) {
  if (i % 2) {
   op1(a);
   op2(b);
  } else {
   op2(a);
   op1(b);
  }
  if (vsorted(a) || vsorted(b)) {
   cout << i + 1 << '\n';
   return 0;
  }
 }
 cout << -1 << '\n';
}