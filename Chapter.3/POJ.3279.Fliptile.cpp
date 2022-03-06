#include <cstdio>
#include <cstring>

const int maxn = 15, inf = 15 * 15;

const int dirs[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int n, m, x, mat[maxn], flip[maxn], res[maxn];

int f(int x, int y) {
    int c = (mat[x] >> y & 1) + (flip[x] >> y & 1);
    for (int i = 0; i < 4; ++i) {
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            c += flip[nx] >> ny & 1;
    }
    return c % 2;
}

int count() {
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < m; ++j)
            flip[i] |= f(i - 1, j) << j;
    for (int j = 0; j < m; ++j)
        if (f(n - 1, j)) return inf;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += __builtin_popcount(flip[i]);
    return cnt;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            scanf("%d", &x);
            mat[i] |= x << j;
        }
    int move = inf;
    for (int i = 0; i < (1 << m); ++i) {
        memset(flip, 0, sizeof flip);
        for (int j = 0; j < m; ++j)
            flip[0] |= i & 1 << j;
        int curr = count();
        if (curr < move) {
            memcpy(res, flip, sizeof flip);
            move = curr;
        }
    }
    if (move == inf)
        printf("IMPOSSIBLE\n");
    else
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                printf("%d%c", (res[i] >> j & 1), (j + 1 < m ? ' ' : '\n'));
    return 0;
}