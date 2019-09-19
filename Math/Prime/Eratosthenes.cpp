/*
・エラトステネスの篩
    > O(NloglogN)
[使用例] vector<bool> prime = Eratosthenes(100000);
[備考] nが10^6以下のときに使うべき.
*/

vector<bool> Eratosthenes(const int n) {
    vector<bool> r(n + 1, true);
    for (int i = 2; i * i <= n; ++i) {
        if (r[i]) {
            for (int j = i * 2; j <= n; j += i) r[j] = false;
        }
    }
    if (r.size() > 2) {
        r[0] = r[1] = false;
    } else if (r.size() > 1) {
        r[0] = false;
    }
    return r;
}
