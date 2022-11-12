#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
 
const vector<int> my{-1, 0, 1, 0}, mx{0, 1, 0, -1};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    // The ith best seat
    vector<int> dist;
    queue<vector<int>> q;
    int d = n/2+m/2;
    q.push({n/2, m/2, d});
    if (n%2 == 0) {
      q.push({n/2-1, m/2, d});
    }
    if (m%2 == 0) {
      q.push({n/2, m/2-1, d});
    }
    if (n%2 == 0 && m%2 == 0) {
      q.push({n/2-1, m/2-1, d});
    }
    // while (q.size()) {
    //   auto p = q.front();
    //   q.pop();
    //   cout << p[0] << ' ' << p[1] << ' ';
    // }
    // cout << '\n';
    vector<vector<bool>> taken(n, vector<bool>(m));
    while (q.size()) {
      auto p = q.front();
      q.pop();
      if (taken[p[0]][p[1]]) {
        continue;
      }
      dist.push_back(p[2]);
      taken[p[0]][p[1]] = true;
      FOR(i, 4) {
        int y = p[0]+my[i], x = p[1]+mx[i];
        if (y >= 0 && y < n && x >= 0 && x < m && !taken[y][x]) {
          q.push({y, x, p[2]+1});
        }
      }
    }
    // FOR(i, dist.size()) {
    //   cout << dist[i] << " \n"[i==(int)dist.size()-1];
    // }
    FOR(i, n*m) {
      cout << dist[i] << ' ';
    }
    cout << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/