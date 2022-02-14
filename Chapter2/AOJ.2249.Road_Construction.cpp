#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

const int maxv = 1e4;
const int inf = 1e9;

struct edge {
    int v, d, c;
    bool operator < (const edge &e) const {
        if (d == e.d) return c < e.c;
        return d > e.d;
    }
};

int dijkstra(vector<edge> g[], int v, int s) {
    pair<int, int> d[maxv];
    fill(d, d + v, make_pair(inf, inf));
    d[s] = {0, 0};
    priority_queue<edge, vector<edge> > que;
    que.push(edge{0, 0, 0});
    while (!que.empty()) {
        edge e = que.top(); que.pop();
        if (d[e.v].first < e.d) continue;
        for (int i = 0; i < g[e.v].size(); ++i) {
            edge ne = g[e.v][i];
            if (d[e.v].first + ne.d < d[ne.v].first ||
                d[e.v].first + ne.d == d[ne.v].first && ne.c < d[ne.v].second) {
                d[ne.v].first = d[e.v].first + ne.d;
                d[ne.v].second = ne.c; 
                que.push(edge{ne.v, d[ne.v].first, d[ne.v].second});
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < v; ++i)
        sum += d[i].second;
    return sum;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m)) {
        if (n + m == 0) break;
        vector<edge> g[maxv];
        for (int i = 0; i < m; ++i) {
            int a, b, d, c;
            scanf("%d %d %d %d", &a, &b, &d, &c);
            g[a - 1].push_back(edge{b - 1, d, c});
            g[b - 1].push_back(edge{a - 1, d, c});
        }
        printf("%d\n", dijkstra(g, n, 0));
    }
    return 0;
}