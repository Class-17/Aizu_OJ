#include <cstdio>

#define MAXN 100
#define MAXM 100

char mat[MAXN][MAXM + 1];

const int dirs[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int N, M;

void dfs(int r, int c, char ch) {
    mat[r][c] = '_';
    for (int i = 0; i < 4; ++i) {
        int nx = r + dirs[i][0], ny = c + dirs[i][1];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && mat[nx][ny] == ch)
            dfs(nx, ny, ch);
    }
}

void solve() {
    int cnt = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (mat[i][j] != '_') {
                dfs(i, j, mat[i][j]);
                cnt++;
            }
    printf("%d\n", cnt);
}

int main() {
    while (scanf("%d %d", &N, &M)) {
        if (N == 0 && M == 0) break;
        for (int i = 0; i < N; ++i)
            scanf("%s", mat[i]);
        solve();
    }
    return 0;
}
