#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100'010;
string S;
int SA[SIZE], GROUP[SIZE], N, d;
bool cmp(int i, int j) {
    if (GROUP[i] != GROUP[j]) return GROUP[i] < GROUP[j];
    i += d;
    j += d;
    return (i < N && j < N) ? (GROUP[i] < GROUP[j]) : (i > j);
}
void constructSA() {
    N = S.size();
    for (int i = 0; i < N; i++) {
        SA[i] = i;
        GROUP[i] = S[i];
    }
    for (d = 1;; d *= 2) {
        sort(SA, SA + N, cmp);
        int tmp[SIZE]{};
        for (int i = 0; i < N - 1; i++) tmp[i + 1] = tmp[i] + cmp(SA[i], SA[i + 1]);
        for (int i = 0; i < N; i++) GROUP[SA[i]] = tmp[i];
        if (tmp[N - 1] == N - 1) break;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> S;
    constructSA();
    for (int i = 0; i < N; i++) cout << SA[i] << "\n";
}