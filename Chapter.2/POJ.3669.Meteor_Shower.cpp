#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 302

const int INF = 1e3 * 2;

const int dirs[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int mat[MAXN][MAXN];


int bfs() {
    int memo[MAXN][MAXN];
    queue<pair<int, int> > q;
    memset(memo, -1, sizeof memo);
    q.push(make_pair(0, 0));
    memo[0][0] = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = p.first + dirs[i][0];
            int ny = p.second + dirs[i][1];
            if (nx < 0 || nx >= MAXN || ny < 0 || ny >= MAXN 
                || memo[p.first][p.second] + 1 >= mat[nx][ny] || memo[nx][ny] > -1) continue;
            memo[nx][ny] = memo[p.first][p.second] + 1;
            if (mat[nx][ny] == INF) return memo[nx][ny];
            q.push(make_pair(nx, ny));
        }
    }
    return -1;
}

int main() {
    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < MAXN; ++j)
            mat[i][j] = INF;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);
        mat[x][y] = min(t, mat[x][y]);
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            if (nx < 0 || nx >= MAXN || ny < 0 || ny >= MAXN) continue;
            mat[nx][ny] = min(t, mat[nx][ny]);
        }
    }
    printf("%d\n", bfs());
    return 0;
}