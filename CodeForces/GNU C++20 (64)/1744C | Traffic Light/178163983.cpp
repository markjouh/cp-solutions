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
        char C;
        string S;
        cin >> N >> C >> S;
        S += S;
        int ans = 0;
        vector<int> mxcost(2*N, 1e9);
        for (int i = 2*N-1; i >= 0; i--) {
            if (S[i] == 'g') {
                mxcost[i] = 0;
            } else if (i < 2*N-1) {
                mxcost[i] = mxcost[i+1]+1;
            }
            if (i < N && S[i] == C) {
                ans = max(ans, mxcost[i]);
            }
        }
        cout << ans << '\n';
    }
}