#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(x) (x).begin(), (x).end()
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, Q;
        cin >> N >> Q;
        vector<int> a(N);
        vector<int> cnt(2);
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            cnt[a[i]%2]++;
            sum += a[i];
        }
        while (Q--) {
            ll t, x;
            cin >> t >> x;
            sum += cnt[t]*x;
            if (x%2) {
                cnt[1-t] += cnt[t];
                cnt[t] = 0;
            }
            cout << sum << '\n';
        }
    }
}