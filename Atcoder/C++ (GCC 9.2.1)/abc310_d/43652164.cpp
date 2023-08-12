#include <bits/stdc++.h>

using namespace std;

#define int int64_t

// a grouping can be represented by a set of sets of player indices
// how can we reformulate this in a simpler/more rigid way so that we can count it?
// the first concern is double-counting due to ordering within inner sets
// so, we should make sure that the player indices in each inner set are in increasing order
// the second concern is double-counting due to ordering among inner sets
// to solve this, we should make sure that the inner sets come in increasing order of their smallest element
// it turns out that all groupings can be uniquely represented by an array of increasing arrays of indices [1..N]

// we can do a recursive bruteforce, on each step deciding whether to create a new group or join an existing one
// this is O(N * N!)

int N, T, M;

bool ban[10][10];
int cur[10];

int ans = 0;

void dfs(int ind, int teams) {
    if (ind == N) {
        ans += teams == T;
        return;
    }
    if (teams < T) {
        cur[ind] = teams + 1;
        dfs(ind + 1, teams + 1);
    }
    vector<bool> ok(T + 1, true);
    for (int i = 0; i < ind; i++) {
        if (ban[ind][i]) {
            ok[cur[i]] = false;
        }
    }
    for (int i = 1; i <= teams; i++) {
        if (ok[i]) {
            cur[ind] = i;
            dfs(ind + 1, teams);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> T >> M;
    memset(ban, 0, sizeof ban);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ban[b][a] = true;
    }
    dfs(0, 0);
    cout << ans << '\n';
}
