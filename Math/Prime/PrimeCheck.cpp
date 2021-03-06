bool isPrime(long long n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false;
    return true;
}

/*
・素数判定
    > O(√n)
[使用例] isPrime(998244353);    // == true
*/
