#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    string S;
    cin >> N >> S;
    vector<int> cnt(2); // cnt[x] = suffixes with NAND = x in the prefix [0..i)
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '0') {
            ans += cnt[0] + cnt[1];
            cnt[1] += cnt[0];
            cnt[0] = 1;
        } else {
            ans += cnt[0] + 1;
            swap(cnt[0], cnt[1]);
            cnt[1]++;
        }
    }
    cout << ans << '\n';
}
