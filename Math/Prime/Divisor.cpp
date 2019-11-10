vector<int_fast64_t> divisor(const int_fast64_t n) {
    vector<int_fast64_t> ret;
    for (int_fast64_t i = 1; i * i <= n; ++i) {
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
[使用例] vector<int_fast64_t> div = divisor(105);
[備考] 整列されていない.
*/
