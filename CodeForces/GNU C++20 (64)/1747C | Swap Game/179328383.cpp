#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
// each player always wants to switch the smallest element in, as it won't hurt them, and it will make the opponent hit 0 faster
// after alice's original move,
// she can make bob take any element other than 0
// bob can make her take any element other than his
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        a[0]--;
        sort(a.begin() + 1, a.end());
        int alice = min(a[0], (n >= 3 ? a[2] : (int)1e9));
        int bob = a[1];
        cout << (bob <= alice ? "Alice\n" : "Bob\n");
    }
}