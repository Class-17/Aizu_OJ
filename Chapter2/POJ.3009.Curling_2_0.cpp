#include <cstdio>
#include <algorithm>

#define MAXN 20
#define MAXM 20

int mat[MAXN + 2][MAXM + 2];

const int dirs[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int N, M, min_step;

bool move(int &r, int &c, int i) {
    int sr = r, sc = c;
    while (true) {
        int nr = r + dirs[i][0], nc = c + dirs[i][1];
        if (mat[nr][nc] == -1) return false;
        if (mat[nr][nc] == 1) return true;
        if (mat[nr][nc] == 3) return true;
        r = nr, c = nc;
    }
    return false;
}

void dfs(int row, int column, int p) {
    if (p == 10) return;
    for (int i = 0; i < 4; ++i) {
        int r = row, c = column;
        if (move(r, c, i)) {
            int nr = r + dirs[i][0], nc = c + dirs[i][1];
            if (mat[nr][nc] == 3) {
                min_step = std::min(p + 1, min_step);
            }
            else if (r != row || c != column) {
                mat[nr][nc] = 0;
                dfs(r, c, p + 1);
                mat[nr][nc] = 1;
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (mat[i][j] == 2) dfs(i, j, 0);
    printf("%d\n", min_step < 11 ? min_step : -1);
}

int main() {
    while (scanf("%d %d", &M, &N)) {
        min_step = 11;
        if (M == 0 && N == 0) break;
        for (int i = 0; i <= N + 1; ++i)
            for (int j = 0; j <= M + 1; ++j)
                mat[i][j] = -1;
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                scanf("%d", &mat[i][j]);
        solve();
    }
    return 0;
}