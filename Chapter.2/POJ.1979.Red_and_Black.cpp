#include <cstdio>

#define MAXN 20
#define MAXM 20

const int dirs[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

char mat[MAXN][MAXM + 1];

int N, M;

int dfs(int r, int c) {
    mat[r][c] = '#';
    int cnt = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = r + dirs[i][0], ny = c + dirs[i][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M || mat[nx][ny] != '.') continue;
        cnt += dfs(nx, ny);
    }
    return cnt;
}

void solve() {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (mat[i][j] == '@')
                printf("%d\n", dfs(i, j));
}

int main() {
    while (scanf("%d %d", &M, &N)) {
        if (N == 0 && M == 0) break;
        for (int i = 0; i < N; ++i)
            scanf("%s", mat[i]);
        solve();
    }
    return 0;
}
