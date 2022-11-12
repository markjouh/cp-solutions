#include <bits/stdc++.h>
using namespace std;
 
int arr[50];
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int n, u;
 cin >> n >> u;
 for (int i = 0; i < n; i++) {
  int a;
  cin >> a;
  a--;
  if (!arr[a]) {
   arr[a] = i + 1;
  }
 }
 for (int i = 0; i < u; i++) {
  int a;
  cin >> a;
  a--;
  cout << arr[a] << ' ';
  for (int j = 0; j < 50; j++) {
   arr[j] += arr[j] < arr[a];
  }
  arr[a] = 1;
 }
 cout << '\n';
}