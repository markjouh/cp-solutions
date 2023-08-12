#include "bits/stdc++.h"

using namespace std;

#define int long long

// suppose bob decides in advance the sides he wants to take
// the optimal state for bob is when he is able to take the greater of both sides when they are different

// if the number of cards on bob's desired side is even at the start, it will be odd on bob's turn (nonzero),
// so bob gets his desired side on all cards

// otherwise, if it's odd, it will be even on bob's turn (can be zero)
// since alice will flip cards N times, bob will at some point be forced into a state where there are zero on his side
// why is this true?
// alice decreases the number of cards on bob's side, since bob can't increase, alice can always force the count to reach 0
// so, bob must take at least one card not on his side

// is it possible for bob to always take exactly one card not on his side in the even case?
// yes
// flip the card with the least difference in bob's configuration
// now, bob can take all the cards in his configuration again, since the count on his side is odd (see case 1)
// this is guaranteed to be the best move, since we can't reach the optimal state, and this is the closest we can get (lose the smallest difference)

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int ans = 0, bob_side = 0, mn_diff = 1e9;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ans += max(a, b);
    if (a >= b) {
      bob_side++;
    }
    mn_diff = min(mn_diff, abs(a - b));
  }
  if (bob_side % 2) {
    ans -= mn_diff;
  }
  cout << ans << '\n';
}
