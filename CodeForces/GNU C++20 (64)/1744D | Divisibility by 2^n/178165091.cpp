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
        int N;
        cin >> N;
        vector<int> a(N), canadd;
        int cnt = 0, totadd = 0;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            while (x%2 == 0) {
                x /= 2;
                cnt++;
            }
            int y = i+1;
            int add = 0;
            while (y%2 == 0) {
                y /= 2;
                add++;
            }
            canadd.push_back(add);
            totadd += add;
        }
 
        if (cnt+totadd < N) {
            cout << -1 << '\n';
            continue;
        }
 
        sort(all(canadd));
        reverse(all(canadd));
        int ans = 0;
        for (int i = 0; i < int(canadd.size()) && cnt < N; i++) {
            if (cnt+canadd[i] <= N) {
                cnt += canadd[i];
                ans++;
            }
        }
        cout << ans << '\n';
    }
}