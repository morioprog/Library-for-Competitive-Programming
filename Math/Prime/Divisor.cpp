vector<long long> divisor(const long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.emplace_back(i);
            if (i * i != n) ret.emplace_back(n / i);
        }
    }
    // sort(ret.begin(), ret.end());
    return ret;
}

/*
・約数列挙
    > O(√n)
[使用例] vector<long long> div = divisor(105);
[備考] 整列されていない.
*/
