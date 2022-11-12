#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  long long x;
  cin >> n >> x;
  queue<long long> q;
  map<long long, int> dist;
  q.push(x);
  dist[x] = 0;
  int ans = 1e9;
  while (!q.empty()) {
    long long f = q.front();
    q.pop();
    if (sz(to_string(f)) == n) {
      ans = min(ans, dist[f]);
    } else {
      for (long long i = f; i > 0; i /= 10) {
        int d = i % 10;
        if (!dist.count(f * d)) {
          q.push(f * d);
          dist[f * d] = dist[f] + 1;
        }
      }
    }
  }
  cout << (ans == 1e9 ? -1 : ans);
}