#include <bits/stdc++.h>
using namespace std;
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define each(x, a) for (auto &x : a)
#define rep(i, a, b) for (int i = a; i < (int)b; i++)
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n, a, b;
 cin >> n >> a >> b;
 vector<pair<int, int>> seals(n);
 each(p, seals) {
  cin >> p.first >> p.second;
 }
 int res = 0;
 rep(i, 0, n) {
  rep(j, i + 1, n) {
   rep(k, 0, 4) {
    int sum = seals[i].first * seals[i].second + seals[j].first * seals[j].second;
    if (seals[i].first <= a && seals[j].first <= a && seals[i].second + seals[j].second <= b) {
     res = max(res, sum);
    }
    if (seals[i].first + seals[j].first <= a && seals[i].second <= b && seals[j].second <= b) {
     res = max(res, sum);
    }
    swap(seals[j].first, seals[j].second);
    if (k % 2) {
     swap(seals[i].first, seals[i].second);
    }
   }
  }
 }
 cout << res << '\n';
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/