constexpr bool EXPAND_TO_MINUS = true;
constexpr int MOD = (int)1e9 + 7;
constexpr int MAX_N = 2020202;
unsigned long long fac[MAX_N], finv[MAX_N], inv[MAX_N];
void COMinit() {
    fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
    for (int i = 2; i < MAX_N; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
unsigned long long C(int n, int r) {
    if (n < r or r < 0) return 0;
    if (n < 0) return EXPAND_TO_MINUS ? ((r % 2 ? -1 : 1) * C(-n + r - 1, r)) : 0;
    return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
}
unsigned long long P(int n, int r) {
    if (n < r or r < 0) return 0;
    return fac[n] * finv[n - r] % MOD;
}
unsigned long long H(int n, int r) {
    if (n == 0 and r == 0) return 1;
    return C(n + r - 1, r);
}

/*
・組み合わせ, 順列, 重複組み合わせ
    > 前計算 O(MAX_N + logMOD)
    > クエリ O(1)
[備考] nが負の際, C(n, r) = (-1) ^ r * C(-n + r - 1, r)として計算.
[使用例]
COMinit();  // MAX_Nまでの前計算
C(n, r);    // nCr (0 <= (n,r) <= MAX_N)
P(n, r);    // nPr ( ... )
H(n, r);    // nHr ( ... )
[verify] https://yukicoder.me/submissions/380715
*/
