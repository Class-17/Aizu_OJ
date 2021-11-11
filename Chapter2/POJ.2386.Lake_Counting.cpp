#include <cstdio>

#define MAX_N 100
#define MAX_M 100

int N, M; 
char field[MAX_N][MAX_M + 1];

void dfs(int x, int y) {
    field[x][y] = '.';
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++) {
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && ny >= 0 && nx < N &&
            ny < M && field[nx][ny] == 'W')
        dfs(nx, ny);
    }
}

void solve() {
    int res = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (field[i][j] == 'W') {
                dfs(i, j);
                res++;
            }
    printf("%d\n", res);
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i)
        scanf("%s", field[i]);
    solve();
	return 0;
}