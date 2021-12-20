#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN = 6;

const int INF = 5000 + 1;

int g[MAXN + 1][MAXN + 1];

int N, R;

int dijkstra(int s, int dest) {
    pair<int, int> d[MAXN + 1];
    fill(d, d + N, make_pair(INF, INF));
    d[s] = make_pair(0, 0);
    for (int i = 1; i <= N; ++i)
        d[i] = make_pair(g[s][i], INF);
    bool memo[MAXN + 1] = {false};
    memo[s] = true;
    while (true) {
        int v = -1;
        for (int i = 1; i <= N; ++i)
            if (!memo[i] && (v == -1 || d[i] < d[v])) v = i;
        if (v == -1) break;
        memo[v] = true;
        for (int i = 1; i <= N; ++i) {
            int curr = d[v].first + g[v][i];
            if (curr < d[i].first)
                swap(curr, d[i].first);
            if (curr > d[i].first && curr < d[i].second)
                swap(curr, d[i].second);
        }
    }
    return d[dest].second;
}

int main() {
    scanf("%d %d", &N, &R);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            g[i][j] = INF;
    for (int i = 0; i < R; ++i) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        g[a][b] = g[b][a] = w;
    }
    printf("%d\n", dijkstra(1, N));
    return 0;
}