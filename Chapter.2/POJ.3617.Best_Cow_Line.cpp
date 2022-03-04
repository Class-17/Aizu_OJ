#include <cstdio>

#define MAXN 2000

char line[MAXN];

int comp(int lo, int hi) {
    while (lo < hi) {
        if (line[lo] < line[hi]) return 1;
        else if (line[lo] > line[hi]) return 0;
        lo++, hi--;
    }
    return 1;
}

int main() {
    int N;
    scanf("%d\n", &N);
    for (int i = 0; i < N; ++i)
        scanf("%c\n", &line[i]);
    int lo = 0, hi = N - 1;
    for (int i = 0; i < N && lo <= hi; ++i) {
        if (comp(lo, hi))
            printf("%c", line[lo++]);
        else
            printf("%c", line[hi--]);
        if ((i + 1) % 80 == 0)
            printf("\n");
    }
    return 0;
}
