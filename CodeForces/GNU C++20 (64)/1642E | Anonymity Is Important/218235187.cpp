#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(x...)
#endif
 
using ll = long long;
 
#define sz(x) static_cast<int>(size(x))
#define all(x) begin(x), end(x)
 
constexpr int INF = INT_MAX / 2;
 
struct Node {
    int top, top_pos, nxt, nxt_pos;
    Node() {
        top = nxt = -INF;
        top_pos = nxt_pos = -1;
    }
    Node(int _top, int _top_pos, int _nxt, int _nxt_pos) {
        top = _top;
        top_pos = _top_pos;
        nxt = _nxt;
        nxt_pos = _nxt_pos;
    }
};
 
int tree_sz;
vector<Node> tree;
 
Node combine(Node a, Node b) {
    if (a.top < b.top) {
        swap(a, b);
    }
    if (b.top > a.nxt) {
        a.nxt = b.top;
        a.nxt_pos = b.top_pos;
    }
    return a;
}
 
void build(vector<int> &a, int x = 0, int tl = 0, int tr = tree_sz) {
    if (tl + 1 == tr) {
        if (tl < sz(a)) {
            tree[x] = Node(a[tl], tl, -INF, -1);
        }
        return;
    }
    int mid = tl + (tr - tl) / 2;
    build(a, 2 * x + 1, tl, mid);
    build(a, 2 * x + 2, mid, tr);
    tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
}
 
Node query(int l, int r, int x = 0, int tl = 0, int tr = tree_sz) {
    if (tl >= r || tr <= l) {
        return Node();
    }
    if (tl >= l && tr <= r) {
        return tree[x];
    }
    int mid = tl + (tr - tl) / 2;
    return combine(query(l, r, 2 * x + 1, tl, mid), query(l, r, 2 * x + 2, mid, tr));
}
 
void solve() {
    int n, q;
    cin >> n >> q;
 
    vector<vector<int>> enter_range(n), exit_range(n); // apply ckmin at time v to [l, r)
    vector<array<int, 3>> pos_ranges; // {left, right, time}
    vector<pair<int, int>> query_status; // {index, time}
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            if (x == 0) {
                enter_range[l - 1].push_back(i);
                exit_range[r - 1].push_back(i);
            } else {
                pos_ranges.push_back({l - 1, r, i});
            }
        } else {
            int j;
            cin >> j;
            j--;
            query_status.push_back({j, i});
        }
    }
 
    multiset<int> active_ranges;
    vector<int> confirmed_healthy(n, INF); // earliest time index i is covered by a range with t = 0, x = 0
    for (int i = 0; i < n; i++) {
        for (int x : enter_range[i]) {
            active_ranges.insert(x);
        }
        if (!active_ranges.empty()) {
            confirmed_healthy[i] = *active_ranges.begin();
        }
        for (int x : exit_range[i]) {
            active_ranges.erase(active_ranges.find(x));
        }
    }
 
    tree_sz = 1;
    while (tree_sz < n) {
        tree_sz *= 2;
    }
    tree.resize(2 * tree_sz);
    build(confirmed_healthy);
 
    vector<int> confirmed_sick(n, INF); // earliest time there is a range with x = 1 such that all indices but i are zero
    for (auto [l, r, time] : pos_ranges) {
        if (l + 1 == r) {
            confirmed_sick[l] = min(confirmed_sick[l], time);
            continue;
        }
 
        Node data = query(l, r);
        dbg(data.top, data.top_pos, data.nxt, data.nxt_pos);
        if (data.nxt != INF) {
            confirmed_sick[data.top_pos] = min(confirmed_sick[data.top_pos], max(data.nxt, time));
        }
    }
 
    for (auto [idx, time] : query_status) {
        if (confirmed_healthy[idx] <= time) {
            cout << "NO\n";
        } else if (confirmed_sick[idx] <= time) {
            cout << "YES\n";
        } else {
            cout << "N/A\n";
        }
    }
 
    dbg(confirmed_healthy);
    dbg(confirmed_sick);
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
 
/*
 
Let b be a binary string of length n, where b_i = 0 if i was covered by a query with x = 0, and 1 otherwise.
 
We know a patient is not sick if and only if b_i = 0.
We know a patient is sick if there is a query with x = 1 such that l <= i < r and sum [l, r) = 1.
 
How do we calculate the answers for t = 1?
We know patient i is not sick if and only if a query with x = 0 covered i before the current query
 
Handle queries with x = 1 separately
We want to find the first time all but one element in its range is covered with zeroes (activation)
 
Compute an array F, where F_i is the first time index i is covered by a range with x = 0 (INF if never)
Queries of type 1 will activate at the time of the second highest element in the range (just handle len = 1 separately)
So, queries of type 1 in [max(query_index, activate), q] with j = i will be YES
For each index, just store the largest such suffix
 
Computing the array of mins can be done using a multiset
Finding the second minimum for each range can be done using a segment tree
 
*/