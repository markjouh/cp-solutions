#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define REP(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = b - 1; i >= (int)a; i--)
#define PER(i, a) ROF(i, 0, a)
 
map<pair<int, int>, int> mp;
 
int q1(int i) {
  cout << "? 1 " << i + 1 << endl;
  char c;
  cin >> c;
  return c - 'a';
}
 
int q2(int l, int r) {
  if (l == r) {
    return 1;
  }
  if (mp.count({l, r})) {
    return mp[{l, r}];
  }
  cout << "? 2 " << l + 1 << ' ' << r + 1 << endl;
  int x;
  cin >> x;
  mp[{l, r}] = x;
  return x;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  int prev_unq = 0;
  vector<int> val(n), last(26, -1);
  REP(i, n) {
    int unq = q2(0, i);
    if (unq != prev_unq) {
      val[i] = q1(i);
      last[val[i]] = i;
      prev_unq = unq;
    } else {
      vector<int> pos;
      REP(j, 26) {
        if (last[j] != -1) {
          pos.push_back(last[j]);
        }
      }
      sort(pos.begin(), pos.end());
      int l = 0, r = pos.size();
      while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        (q2(pos[mid], i) == (int)pos.size() - mid ? l : r) = mid;
      }
      val[i] = val[pos[l]];
      last[val[i]] = i;
    }
  }
  cout << "! ";
  REP(i, n) {
    cout << (char)(val[i] + 'a');
  }
  cout << endl;
}