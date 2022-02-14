#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

const int maxn = 1e4 - 1;

typedef pair<int, int> pii;

bitset<maxn + 1> st;

vector<int> g[maxn];

void sieve() {
    for (int i = 2; i <= maxn; ++i) {
        if (st[i]) continue;
        for (int j = i + i; j <= maxn; j += i)
            st[j] = true;
    }
}

void build() {
    for (int x = 1000; x <= maxn; ++x) {
        if (st[x]) continue;
        for (int i = 1; i < 10000; i *= 10) {
            for (int j = 0; j < 10; ++j) {
                int y = (x / i / 10) * i * 10 + j * i + x % i;
                if (x == y || st[y] || y < 1000) continue;
                g[x].push_back(y);
                g[y].push_back(x);
            }
        }
    }
}

int dijkstra(int s, int t) {
    priority_queue<pii, vector<pii>, greater<pii> > pq; 
    int d[maxn];
    memset(d, 0x3f, sizeof d);
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int du = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d[u] < du) continue;
        if (u == t) return du;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (du + 1 < d[v]) {
                d[v] = du + 1;
                pq.push({d[v], v});
            }
        }
    }
    return -1;
}

int main() {
    sieve();
    build();
    int _;
    !scanf("%d", &_);
    while (_--) {
        int a, b;
        !scanf("%d %d", &a, &b);
        int res = dijkstra(a, b);
        if (res == -1)
            printf("Impossible\n");
        else
            printf("%d\n", res);
    }
    return 0;
}