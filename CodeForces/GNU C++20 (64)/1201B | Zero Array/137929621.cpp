#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> nums(n);
 long long sum = 0;
 for (int &x : nums) {
  cin >> x;
  sum += x;
 }
 bool OK = sum % 2 == 0;
 for (int x : nums) {
  OK &= sum - x >= x;
 }
 cout << (OK ? "YES" : "NO") << '\n';
}