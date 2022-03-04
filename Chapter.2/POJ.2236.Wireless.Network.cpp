#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 1001;

struct computer {
    int x, y, p;
    bool work;
} ds[MAXN + 1];

int find(int x) {
    if (ds[x].p < 0) return x;
    return ds[x].p = find(ds[x].p);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (ds[x].p > ds[y].p) swap(x, y);
    ds[x].p += ds[y].p;
    ds[y].p = x;
}

bool check(computer &a, computer &b, int d) {
    return d * d - (a.x - b.x) * (a.x - b.x) >= (a.y - b.y) * (a.y - b.y);
}

int main() {
    int N, d;
    scanf("%d %d", &N, &d);
    for (int i = 1; i <= N; ++i) {
        scanf("%d %d\n", &ds[i].x, &ds[i].y);
        ds[i].p = -1;
        ds[i].work = false;
    }
    char op;
    while (scanf("%c", &op) != EOF) {
        if (op == 'O') {
            int p;
            scanf("%d\n", &p);
            ds[p].work = true;
            for (int i = 1; i <= N; ++i)
                if (check(ds[i], ds[p], d) && ds[i].work)
                    unite(i, p);
        }
        else {
            int p, q;
            scanf("%d %d\n", &p, &q);
            printf("%s\n", find(p) == find(q) ? "SUCCESS" : "FAIL");
        }
    }
    return 0;
}
