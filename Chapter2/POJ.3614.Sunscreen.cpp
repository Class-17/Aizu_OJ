#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>

#define fi first
#define se second

using namespace std;

const int MAXN = 2500;

typedef pair<int, int> PII;


int main() {
    int C, L;
    scanf("%d %d", &C, &L);
    PII c[MAXN], l[MAXN];
    for (int i = 0; i < C; ++i)
        scanf("%d %d", &c[i].fi, &c[i].se);
    for (int i = 0; i < L; ++i)
        scanf("%d %d", &l[i].fi, &l[i].se);
    sort(c, c + C);
    sort(l, l + L);
    priority_queue<int, vector<int>, greater<int> > pq;
    int res = 0;
    for (int i = 0, j = 0; i < L; ++i) {
        while (j < C && l[i].fi >= c[j].fi) {
            pq.push(c[j].se);
            j++;
        }
        while (!pq.empty() && l[i].se > 0) {
            if (pq.top() >= l[i].fi) {
                res++;
                l[i].se--;
            }
            pq.pop();
        }
    }
    printf("%d\n", res);
    return 0;
}
