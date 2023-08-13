#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
 
using namespace std;
 
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define F first
#define S second
 
#define VE vector
#define AR array
 
typedef long long LL;
typedef pair<int, int> PII;
 
void solve() {
    int N, M;
    cin >> N >> M;
    VE<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    VE<int> vals = A;
    sort(ALL(vals));
    vals.resize(unique(ALL(vals)) - vals.begin());
    for (int i = 0; i < N; i++) {
        A[i] = lower_bound(ALL(vals), A[i]) - vals.begin();
    }
    VE<AR<int, 3>> Q(M);
    for (int i = 0; i < M; i++) {
        cin >> Q[i][0] >> Q[i][1];
        Q[i][0]--;
        Q[i][1]--;
        Q[i][2] = i;
    }
    int block = 1;
    while (block * block < N) {
        block++;
    }
    sort(ALL(Q), [&](AR<int, 3> A, AR<int, 3> B) {
        if (A[0] / block != B[0] / block) {
            return A[0] / block < B[0] / block;
        }
        return A[1] < B[1];
    });
    vector<int> freq(N);
    int cur = 0;
    auto op = [&](int i, int d) {
        cur -= freq[i] == vals[i];
        freq[i] += d;
        cur += freq[i] == vals[i];
    };
    for (int i = Q[0][0]; i <= Q[0][1]; i++) {
        op(A[i], 1);
    }
    int l = Q[0][0], r = Q[0][1];
    vector<int> ans(M);
    ans[Q[0][2]] = cur;
    for (int i = 1; i < M; i++) {
        while (l < Q[i][0]) {
            op(A[l++], -1);
        }
        while (l > Q[i][0]) {
            op(A[--l], 1);
        }
        while (r < Q[i][1]) {
            op(A[++r], 1);
        }
        while (r > Q[i][1]) {
            op(A[r--], -1);
        }
        ans[Q[i][2]] = cur;
    }
    for (int i = 0; i < M; i++) {
        cout << ans[i] << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}