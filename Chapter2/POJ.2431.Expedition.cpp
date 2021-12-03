#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1e4;

struct town {
    int d, w;
    bool operator < (const town &t) const {
        return d > t.d;
    }
} towns[MAXN + 1];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d %d", &towns[i].d, &towns[i].w);
    sort(towns, towns + N);
    towns[N].d = towns[N].w = 0;
    int L, P;
    scanf("%d %d", &L, &P);
    priority_queue<int> pq;
    int res = 0;
    for (int i = 0; i <= N; ++i) {
        P -= L - towns[i].d;
        while (P < 0 && !pq.empty()) {
            P += pq.top();
            pq.pop();
            res++;
        }
        if (P < 0) break;
        L = towns[i].d;
        pq.push(towns[i].w);
    }
    printf("%d\n", P >= 0 ? res : -1);
	return 0;
}