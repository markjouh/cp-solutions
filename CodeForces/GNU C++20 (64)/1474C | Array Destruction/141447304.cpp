#include <bits/stdc++.h>
using namespace std;
 
/*
Write the algorithm like this
 
sort multiset
for i = 0, i < n*2-1
  make a copy of multiset (st)
  set last to mx
  erase mx
  erase multiset begin+i
  repeat n-1 times
    if st has last-bk
      erase it
    else
      clear answer
      break
  
*/
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    multiset<int> MS;
    for (int i = 0; i < n*2; i++) {
      int x;
      cin >> x;
      MS.insert(x);
    }
    vector<pair<int, int>> res;
    for (int i = 0; i < n*2-1; i++) {
      multiset<int> ms = MS;
      auto fi = --ms.end(), se = ms.begin();
      advance(se, i);
      int last = *fi;
      ms.erase(fi);
      ms.erase(se);
      res.push_back({*fi, *se});
      bool ok = true;
      for (int j = 0; j < n-1; j++) {
        int bk = *ms.rbegin();
        ms.erase(ms.find(bk));
        auto f = ms.find(last-bk);
        if (f == ms.end()) {
          ok = false;
          break;
        }
        res.push_back({bk, *f});
        ms.erase(f);
        last = bk;
      }
      if (ok) {
        break;
      } else {
        res.clear();
      }
    }
    if (res.size()) {
      cout << "YES" << '\n' << res[0].first+res[0].second << '\n';
      for (auto [f, s] : res) {
        cout << f << ' ' << s << '\n';
      }
    } else {
      cout << "NO" << '\n';
    }
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/