#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0, x; i < N; ++i) {
        scanf("%d", &x);
        q.push(x);
    }
    long long cost = 0;
    while (q.size() > 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        cost += a + b;
        q.push(a + b);
    }
    printf("%lld\n", cost);
    return 0;
}
