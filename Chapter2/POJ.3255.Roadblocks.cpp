#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 5000;

const int INF = 1e9;

typedef pair<int, int> PII;

vector<PII> g[MAXN + 1];

int N, R;

int dijkstra(int s, int dest) {
    pair<int, int> d[MAXN + 1];
    fill(d, d + N + 1, PII(INF, INF));
    d[s] = PII(0, INF);
    priority_queue<PII, vector<PII>, greater<PII> > que;
    que.push(PII(0, 1));
    while (!que.empty()) {
        PII x = que.top(); que.pop();
        int v = x.second, w = x.first;
        if (d[v].second < w) continue;
        for (int i = 0; i < g[v].size(); ++i) {
            int nv = g[v][i].first;
            int curr = w + g[v][i].second;
            if (curr < d[nv].first) {
                que.push(PII(curr, nv));
                swap(curr, d[nv].first);
            }
            if (curr > d[nv].first && curr < d[nv].second) {
                que.push(PII(curr, nv));
                swap(curr, d[nv].second);
            }
        }
    }
    return d[dest].second;
}

int main() {
    scanf("%d %d", &N, &R);
    for (int i = 0; i < R; ++i) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        g[a].push_back(PII(b, w));
        g[b].push_back(PII(a, w));
    }
    printf("%d\n", dijkstra(1, N));
    return 0;
}