map<long long, int> prime_factor(long long n) {
    map<long long, int> ret;
    for (long long i = 2; i * i <= n; ++i) {
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
[使用例] map<long long, int> mp = prime_factor(105);
[応用例] (mpの各要素のsecond) + 1を掛け合わせると, nの約数の個数
*/
