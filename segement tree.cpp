#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int SIZE = 1 << 21;
struct segTree {
    long long arr[SIZE];
    int start;
    segTree(int N) {
        start = 1;
        for (; start < N; start *= 2)
            ;
        memset(arr, 0, sizeof(arr));
    }
    void update(int i, int val) {
        i += start;
        arr[i] = val;
        while (i > 1) {
            i /= 2;
            arr[i] = arr[i * 2] + arr[i * 2 + 1];
        }
    }
    // 구간 [L, R)에 대해
    long long getSum(int L, int R) { return getSum(L, R, 1, 0, start); }
    long long getSum(int L, int R, int node, int nL, int nR) {
        if (R <= nL || nR <= L) return 0;
        if (L <= nL && nR <= R) return arr[node];
        int mid = (nL + nR) / 2;
        return getSum(L, R, node * 2, nL, mid) + getSum(L, R, node * 2 + 1, mid, nR);
    }
};
