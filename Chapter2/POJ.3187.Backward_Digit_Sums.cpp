#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, sum, a[10];
    scanf("%d %d", &N, &sum);
	for (int i = 0; i < N; ++i)
        a[i] = i + 1;
    do {
        int t[10];
        for (int i = 0; i < N; ++i)
            t[i] = a[i];
        for (int i = N - 1; i > 0; --i) {
            for (int j = 0; j < i; ++j)
                t[j] += t[j + 1];
        }
        if (t[0] == sum) break;
    } while (next_permutation(a, a + N));
    for (int i = 0; i < N; ++i)
        printf("%d%c", a[i], i < N - 1 ? ' ' : '\n');
	return 0;
}