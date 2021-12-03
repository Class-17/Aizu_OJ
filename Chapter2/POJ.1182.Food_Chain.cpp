#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5e4;

int ds[MAXN * 3 + 1];

int find(int x) {
	if (ds[x] < 0) return x;
	return ds[x] = find(ds[x]);
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (ds[x] > ds[y]) swap(x, y);
	ds[x] += ds[y];
	ds[y] = x;
}

bool check(int x, int y) {
	return find(x) == find(y);
}

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	memset(ds, -1, sizeof(ds));
	int res = 0;
	for (int i = 0; i < K; ++i) {
		int d, x, y;
		scanf("%d %d %d", &d, &x, &y);
		if (x <= 0 || x > N || y <= 0 || y > N)
			res++;
		else if (d == 1) {
			if (check(x, y + N) || check(x, y + N * 2))
				res++;
			else {
				unite(x, y);
				unite(x + N, y + N);
				unite(x + N * 2, y + N * 2);
			}
		}
		else {
			if (check(x, y) || check(x, y + N))
				res++;
			else {
				unite(x, y + N * 2);
				unite(x + N, y);
				unite(x + N * 2, y + N);
			}
		}
	}
	printf("%d\n", res);
	return 0;
}