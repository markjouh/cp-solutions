#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
/*
once two cards in a set are chosen, the third one is fixed.
at a position i, if the two cards have different values, then the third one must be the one that hasn't occurred yet.
if they have the same value, the third one must have that value as well.
 
in a meta-set of 5 cards, there will be exactly 2 sets and no more.
suppose we currently have a set of 5 distinct cards. out of these 5 cards, 3 form a valid set (A). now, we have 2 cards that aren't part
of any set yet (B).
it's impossible for us to form a set out of 2 cards in A with 1 card in B, as the third card in a set is fixed, and all the cards are
distinct, meaning that a card in B can't be the same as a card in A.
thus, the only way to form another set is to combine 1 card in A with 2 cards in B.
 
to calculate the answer, we can count the number of valid meta-sets for all possible "intersection" cards.
*/
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cards(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cards[i][j];
        }
    }
    set<string> st;
    for (int i = 0; i < n; i++) {
        string s;
        for (int j = 0; j < m; j++) {
            s += '0' + cards[i][j];
        }
        st.insert(s);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll pairs = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            string s;
            for (int k = 0; k < m; k++) {
                if (cards[i][k] != cards[j][k]) {
                    vector<bool> used(3);
                    used[cards[i][k]] = true;
                    used[cards[j][k]] = true;
                    for (int l = 0; l < 3; l++) {
                        if (!used[l]) {
                            s += '0' + l;
                            break;
                        }
                    }
                } else {
                    s += '0' + cards[i][k];
                }
            }
            // cerr << i << ' ' << j << ' ' << s << '\n';
            pairs += st.count(s);
        }
        cerr << pairs << '\n';
        pairs /= 2;
        if (pairs > 1) {
            ans += pairs * (pairs - 1) / 2;
        }
        
    }
    cout << ans << '\n';
}