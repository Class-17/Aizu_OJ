#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e5;

int find(int ds[], int x) {
    if (ds[x] < 0) return x;
    return ds[x] = find(ds, ds[x]);
}

void unite(int ds[], int a, int b) {
    a = find(ds, a), b = find(ds, b);
    if (a == b) return;
    if (ds[a] > ds[b]) swap(a, b);
    ds[a] += ds[b];
    ds[b] = a;
}

int main() {
    int _;
    scanf("%d", &_);
    while (_--) {
        int N, M, ds[MAXN + 1], rev[MAXN + 1] = {0};
        scanf("%d %d\n", &N, &M);
        memset(ds, -1, sizeof(ds));
        for (int i = 0; i < M; ++i) {
            char op;
            int a, b;
            scanf("%c %d %d\n", &op, &a, &b);
            bool init = false;
            if (op == 'D') {
                if (rev[a] == 0) rev[a] = b;
                else             unite(ds, rev[a], b);
                if (rev[b] == 0) rev[b] = a;
                else             unite(ds, rev[b], a);
            }
            else {
                int x = find(ds, a), y = find(ds, b);
                if (a == b)
                    printf("In the same gang.\n");
                else if (rev[a] != 0 && find(ds, rev[a]) == y)
                    printf("In different gangs.\n");  
                else if (rev[b] != 0 && find(ds, rev[b]) == x)
                    printf("In different gangs.\n");
                else if (rev[a] != 0 && rev[b] != 0 && find(ds, rev[a]) == find(ds, rev[b]))
                    printf("In the same gang.\n");
                else
                    printf("Not sure yet.\n");
            }
        }
    }
    return 0;
}
