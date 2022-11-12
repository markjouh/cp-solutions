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
  vector<int> stack;
  for (int rep = 0; rep < n; rep++) {
   int x;
   cin >> x;
   if (x == 1) {
    stack.push_back(1);
   } else {
    while (stack.back() != x - 1) {
     stack.pop_back();
    }
    stack.back()++;
   }
   for (int i = 0; i < stack.size() - 1; i++) {
    cout << stack[i] << '.';
   }
   cout << stack[stack.size() - 1] << '\n';
  }
 }
}