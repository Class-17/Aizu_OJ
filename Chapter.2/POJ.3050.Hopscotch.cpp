#include <cstdio>
#include <vector>
#include <set>
#define MAXN 5

using namespace std;

const int dirs[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int mat[MAXN][MAXN];

vector<int> comb(6);
set<vector<int> > combs;

void dfs(int r, int c, int p) {
	if (p == 6) {
		combs.insert(comb);
		return;
	}
	comb[p] = mat[r][c];
	for (int i = 0; i < 4; ++i) {
		int nr = r + dirs[i][0];
		int nc = c + dirs[i][1];
		if (nr < 0 || nr >= MAXN || nc < 0 || nc >= MAXN) continue;
		dfs(nr, nc, p + 1);
	}
}

int main() {
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXN; ++j)
			scanf("%d", &mat[i][j]);
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXN; ++j)
			dfs(i, j, 0);
	printf("%d\n", int(combs.size()));
	return 0;
}