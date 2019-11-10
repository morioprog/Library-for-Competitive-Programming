map<int_fast64_t, int> prime_factor(int_fast64_t n) {
    map<int_fast64_t, int> ret;
    for (int_fast64_t i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++ret[i];
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

/*
・素因数分解
    > O(√n)
[使用例] map<int_fast64_t, int> mp = prime_factor(105);
[応用例] (mpの各要素のsecond) + 1を掛け合わせると, nの約数の個数
*/
