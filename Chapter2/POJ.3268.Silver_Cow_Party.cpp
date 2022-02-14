#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

const int maxv = 1e3;
const int inf = 1e8;

typedef pair<int, int> pii;

void dijkstra(int n, int s, vector<pii> e[], int d[]) {
    fill(d, d + n, inf);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({d[s] = 0, s});
    while (!pq.empty()) {
        int a = pq.top().second, w = pq.top().first;
        pq.pop();
        if (w > d[a]) continue;
        for (int i = 0; i < e[a].size(); ++i) {
            int b = e[a][i].first, cost = e[a][i].second;
            if (d[a] + cost < d[b])
                pq.push({d[b] = d[a] + cost, b});
        }
    }
}

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    vector<pair<int, int> > ef[maxv], eb[maxv];
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        ef[a - 1].push_back({b - 1, w});
        eb[b - 1].push_back({a - 1, w});
    }
    int df[maxv], db[maxv];
    dijkstra(n, x - 1, ef, df);
    dijkstra(n, x - 1, eb, db);
    int max_time = 0;
    for (int i = 0; i < n; ++i)
        max_time = max(df[i] + db[i], max_time);
    printf("%d\n", max_time);
    return 0;
}