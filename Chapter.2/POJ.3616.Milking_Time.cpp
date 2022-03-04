#include <cstdio>
#include <set>
#include <algorithm>

#define ll long long

using namespace std;

const int MAXM = 1e3;

struct cow {
    ll l, r, e;
    bool operator < (const cow& c) const {
        return l < c.l;
    }
} cows[MAXM];

struct itv {
    ll p, sum;
    bool operator < (const itv& x) const {
        return p < x.p;
    }
    itv(ll p, ll sum) {
        this->p = p;
        this->sum = sum;
    }
};

int main() {
	int N, M, R;
    scanf("%d%d%d", &N, &M, &R);
    for (int i = 0; i < M; ++i)
        scanf("%lld%lld%lld", &cows[i].l, &cows[i].r, &cows[i].e);
    sort(cows, cows + M);
    set<itv> dp;
    for (int i = 0; i < M; ++i) {
        set<itv>::iterator it = dp.begin();
        itv obj(0, 0);
        while (it != dp.end() && it->p <= cows[i].l) {
            if (it->sum > obj.sum) obj = *it;
            it++;
        }
        obj = itv(cows[i].r + R, cows[i].e + obj.sum);
        it = dp.lower_bound(obj);
        if (it != dp.end() && it->p == obj.p) {
            obj.sum = max(it->sum, obj.sum);
            dp.erase(it);
        }
        dp.insert(obj);
    }
    ll res = 0;
    for (set<itv>::iterator it = dp.begin(); it != dp.end(); ++it)
        res = max(it->sum, res);
    printf("%lld\n", res);
	return 0;
}