#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>

#define fi first
#define se second
#define ll long long

using namespace std;

const int MAXC = 1e5;

typedef pair<int, int> PII;
typedef priority_queue<int> PQI;

int N, C, F;

PII cows[MAXC];

ll get_cost(PQI &pq, int i, ll &sum) {
    if (pq.size() < N / 2) {
        sum += cows[i].se;
        pq.push(cows[i].se);
    }
    else if (!pq.empty() && pq.top() > cows[i].se) {
        sum = sum - pq.top() + cows[i].se;
        pq.pop();
        pq.push(cows[i].se);
    }
    return sum;
}

int main() {
    scanf("%d %d %d", &N, &C, &F);
    for (int i = 0; i < C; ++i)
        scanf("%d %d", &cows[i].fi, &cows[i].se);
    sort(cows, cows + C);
    ll left_cost[MAXC + 1] = {0}, right_cost[MAXC + 1] = {0};
    PQI pq_l, pq_r;
    ll sum_l = 0, sum_r = 0;
    for (int i = 0; i < C; ++i)
        left_cost[i] = get_cost(pq_l, i, sum_l);
    for (int i = C - 1; i >= 0; --i)
        right_cost[i] = get_cost(pq_r, i, sum_r);
    int res = -1;
    for (int i = N / 2; i + N / 2 < C; ++i)
        if (left_cost[i - 1] + right_cost[i + 1] + cows[i].se <= F)
            res = cows[i].fi;
    printf("%d\n", res);
    return 0;
}
