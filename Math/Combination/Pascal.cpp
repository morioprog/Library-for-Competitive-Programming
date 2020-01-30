unsigned long long comb(unsigned long long n, unsigned int r) {
    if (r == 0) return 1;
    if (n < 0) return comb(-n + r - 1, r) * (r % 2 ? -1 : 1);
    if (n == 0 || r < 0 || n < r) return 0;
    unsigned long long ret = 1;
    for (unsigned long long i = 1; i <= r; ++i) (ret *= n--) /= i;
    return ret;
}

/*
・nが大きい(rが小さい)ときの組み合わせ
    > クエリ O(r)
[使用例] comb(n, r);     // nCr
*/
