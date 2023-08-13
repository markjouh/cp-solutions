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
#include <random>
#include <set>
#include <vector>
 
using namespace std;
 
#define int int64_t
 
// the edges connect two vertices
// at the end, we will have some number of cycles and some number of bamboo trees
// the min is cycles + 1
// the max is cycles + bamboo trees
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<set<int>> G(N);
        for (int u = 0; u < N; u++) {
            int v;
            cin >> v;
            v--;
            G[u].insert(v);
            G[v].insert(u);
        }
        int cnt = 0;
        vector<int> comp(N, -1);
        for (int i = 0; i < N; i++) {
            if (comp[i] == -1) {
                comp[i] = cnt++;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v : G[u]) {
                        if (comp[v] == -1) {
                            comp[v] = comp[u];
                            q.push(v);
                        }
                    }
                }
            }
        }
        vector<int> is_cycle(N, true);
        for (int i = 0; i < N; i++) {
            is_cycle[comp[i]] &= G[i].size() == 2;
        }
        int cycles = 0, bamboo = 0;
        for (int i = 0; i < cnt; i++) {
            (is_cycle[i] ? cycles : bamboo)++;
        }
        cout << cycles + (bamboo > 0) << ' ' << cycles + bamboo << '\n';
    }
}