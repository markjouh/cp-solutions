#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
// the answer is always mx_1 + mx_2 - mn_1 - mn_2
// there will always be a mn next to a mx in a list of 4, ordered by position
// it doesn't matter which mn is connected to which mx, as they sum up to the same thing
 
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
        sort(all(a));
        cout << a[n - 1] + a[n - 2] - a[0] - a[1] << '\n';
    }
}