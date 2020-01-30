template<typename T> long long InversionNumber(vector< T > &v) {
    long long sz = v.size(), ret = 0;
    vector< T > rev, v_cp = v; sort(v_cp.begin(), v_cp.end());
    for (auto &e : v) rev.emplace_back(lower_bound(v_cp.begin(), v_cp.end(), e) - v_cp.begin());
    BinaryIndexedTree< T > bit(sz);
    for (int i = 0; i < sz; ++i) {
        ret += i - bit.sum(rev[i]);
        bit.add(rev[i], 1);
    }
    return ret;
}

/*
・転倒数 (Inversion Number)
    > O(NlogN)
[備考] i < j かつ a_i > a_j となる組(i, j)の個数. バブルソートのスワップ回数と等しい.
[注意] BinaryIndexedTreeを上で定義しておくこと.
[使用例]
vector<int> v = {3, 1, 5, 4, 2};
InversionNumber(v);     // == 5 : vの転倒数
*/
