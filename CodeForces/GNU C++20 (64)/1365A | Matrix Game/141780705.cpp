#include <bits/stdc++.h>
using namespace std;
 
// Trying these out
typedef long long ll;
#define bg begin()
#define ed end()
#define f first
#define s second
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<bool> row(n, true), col(m, true);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        bool x;
        cin >> x;
        row[i] = row[i]&!x;
        col[j] = col[j]&!x;
      }
    }
    int rows = accumulate(row.bg, row.ed, 0), cols = accumulate(col.bg, col.ed, 0);
    cout << (min(rows, cols)%2 ? "Ashish\n" : "Vivek\n");
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/