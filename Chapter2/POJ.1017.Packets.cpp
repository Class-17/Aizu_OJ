#include <cstdio>

int main() {
    int a1, a2, a3, a4, a5, a6;
    while (scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5, &a6)) {
        if (a1 + a2 + a3 + a4 + a5 + a6 == 0) break;
        int sum = (a3 + 3) / 4 + a4 + a5 + a6;
        int rp_a2 = a4 * 5 + (a3 % 4 > 0 ? (4 - a3 % 4) * 2 - 1 : 0);
        if (a2 > rp_a2) sum += (a2 - rp_a2 + 8) / 9;
        int rp_a1 = 36 * sum - 36 * a6 - 25 * a5 - 16 * a4 - 9 * a3 - 4 * a2;
        if (a1 > rp_a1) sum += (a1 - rp_a1 + 35) / 36;
        printf("%d\n", sum);
    }
    return 0;
}