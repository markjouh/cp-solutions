#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
 
#define VE vector
#define AR array
 
#define FOR(i, A, B) for (int i = A; i < B; i++)
#define F0R(i, N) FOR(i, 0, N)
#define RFOR(i, A, B) for (int i = B - 1; i >= A; i--)
#define RF0R(i, N) RFOR(i, 0, N)
#define REP(N) F0R(_, N)
 
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define LB lower_bound
#define UB upper_bound
#define PB push_back
#define F first
#define S second
 
void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    F0R(i, N) {
        cin >> A[i];
    }
    int l = 0;
    while (l < N) {
        int mn_pos = min_element(A.begin() + l, A.end()) - A.begin();
        for (int i = mn_pos; i > l; i--) {
            swap(A[i], A[i - 1]);
        }
        if (mn_pos == l) {
            l++;
        } else {
            l = mn_pos;
        }
    }
    F0R(i, N) {
        cout << A[i] << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
 
// Read the statement carefully, take your time
// Don't be intimidated, the solution is probably simpler than you think
// CM soon :pray: