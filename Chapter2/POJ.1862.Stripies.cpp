#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    priority_queue<double> pq;
    for (int i = 0; i < N; ++i) {
		double x;
		scanf("%lf", &x);
		pq.push(x);
    }
    while (pq.size() > 1) {
        double m1 = pq.top(); pq.pop();
        double m2 = pq.top(); pq.pop();
        pq.push(2 * sqrt(m1 * m2));
    }
    printf("%.3f\n", pq.top());
    return 0;
}
