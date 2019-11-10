uint_fast64_t comb(uint_fast64_t n, uint_fast32_t r) {
    if (r == 0) return 1;
    if (n < 0) return comb(-n + r - 1, r) * (r % 2 ? -1 : 1);
    if (n == 0 || r < 0 || n < r) return 0;
    uint_fast64_t ret = 1;
    for (uint_fast64_t i = 1; i <= r; ++i) (ret *= n--) /= i;
    return ret;
}

/*
・nが大きい(rが小さい)ときの組み合わせ
    > クエリ O(r)
[使用例] comb(n, r);     // nCr
*/
