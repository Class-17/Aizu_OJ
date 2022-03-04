#include <cstdio>
#include <cstring>
#include <cctype>

typedef long long ll;

const int maxn = 1e5;

int x[maxn], y[maxn], z[maxn], n;

ll check(int t) {
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (t < x[i]) continue;
        ll num = (t <= y[i] ? t : y[i]) - x[i];
        cnt += num / z[i] + 1;
    }
    return cnt;
}

void solve() {
    ll lo = 1, hi = 1LL << 31;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        ll cnt = check(mid);
        if (!(cnt & 1)) lo = mid + 1;
        else            hi = mid;
    }
    ll cnt = check(lo) - check(lo - 1);
    if (!(cnt & 1))
        printf("no corruption\n");
    else
        printf("%lld %lld\n", lo, cnt);
}

int read(int &i, char *s, int len) {
    int x = 0;
    while (i < len && isdigit(s[i]))
        x = x * 10 + (s[i++] - '0');
    ++i;
    return x;
}

int read(char *s) {
    char ch;
    int i = 0;
    do {
        if (scanf("%c", &ch) == EOF) return EOF;
        s[i++] = ch;
    } while (ch != '\n');
    return 0;
}

int main() {
    char s[50] = "\n";
    n = 0;
    while (~read(s)) {
        if (s[0] == '\n') {
            if (n > 0) {
                solve();
                n = 0;
            }
            continue;
        }
        int len = strlen(s);
        int i = 0;
        x[n] = read(i, s, len);
        y[n] = read(i, s, len);
        z[n] = read(i, s, len);
        ++n;
       s[0] = '\n';
    }
    if (n > 0) solve();
    return 0;
}
