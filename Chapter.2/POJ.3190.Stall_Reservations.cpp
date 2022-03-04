#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
const int MAXN = 50000;

int stalls[MAXN];

struct cow {
    int x, y, id;
    bool operator < (const cow &c) const {
        return x < c.x;
    }
} cows[MAXN];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &cows[i].x, &cows[i].y);
        cows[i].id = i;
    }
    int num = 1, min_val = 0;
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    sort(cows, cows + N);
    for (int i = 0; i < N; ++i) {
        if (pq.empty() || cows[i].x <= pq.top().first) {
            pq.push(make_pair(cows[i].y, num));
            stalls[cows[i].id] = num++;
        }
        else {
            PII x = pq.top();
            pq.pop();
            pq.push(make_pair(cows[i].y, x.second));
            stalls[cows[i].id] = x.second;
        }
        min_val = max(int(pq.size()), min_val);
    }
    printf("%d\n", min_val);
    for (int i = 0; i < N; ++i)
        printf("%d\n", stalls[i]);
    return 0;
}