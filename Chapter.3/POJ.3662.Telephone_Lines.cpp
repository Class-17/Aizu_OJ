#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1000;

typedef pair<int, int> pii;

vector<pii> g[maxn + 1];

int n, p, k;

int dijkstra(int x) {
    int d[maxn + 1];
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        int du = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d[u] < du) continue;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i].first, w = g[u][i].second;
            int del = (w > x);
            if (du + del < d[v]) {
                d[v] = du + del;
                pq.push({d[v], v});
            }
        }
    }
    return d[n];
}

int main() {
    scanf("%d %d %d", &n, &p, &k);
    for (int i = 0; i < p; ++i) {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        g[a].push_back({b, l});
        g[b].push_back({a, l});
    }
    int lo = 0, hi = 1e6;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (dijkstra(mid) > k) lo = mid + 1;
        else                   hi = mid;
    }
    int res = dijkstra(lo) < 0x3f3f3f3f ? lo : -1;
    printf("%d\n", res);
    return 0;
}