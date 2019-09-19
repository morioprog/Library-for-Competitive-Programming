/*
・ローリングハッシュ
[備考] 文字列をハッシュとして管理する. ハッシュ値の衝突に注意.
[使用例]
RH rh = init(S);            // 文字列Sでハッシュを構築
get(rh, l, r);              // 半開区間[l, r)のハッシュ値を取得
rotate(rh, idx, len_s);     // 文字列をidxの位置でrotateしたものを返す
[ToDo] 回文判定
*/

template<int mod, int base=10007>
struct RollingHash {
    vector<uint_fast64_t> hsh, pwr;
    uint_fast64_t umod(uint_fast64_t n) { return (n % mod + mod) % mod; }
    RollingHash() {}
    RollingHash(const string &s) {
        int sz = (int)s.size();
        hsh.assign(sz + 1, 0);
        pwr.assign(sz + 1, 0);  pwr[0] = 1;
        for (int i = 0; i < sz; ++i) {
            if (sz > i) hsh[i + 1] = umod(hsh[i] * base + s[i]);
            pwr[i + 1] = umod(pwr[i] * base);
        }
    }
    // [l, r)
    uint_fast64_t get(int l, int r) {
        return umod(hsh[r] - hsh[l] * pwr[r - l]);
    }
    // h1 <- h2
    uint_fast64_t join(uint_fast64_t h1, uint_fast64_t h2, int h2_sz) {
        return umod(h1 * pwr[h2_sz] + h2);
    }
    // [idx, len_s) + [0, idx)
    uint_fast64_t rotate(uint_fast64_t idx, int len_s) {
        return join(get(idx, len_s), get(0, idx), idx);
    }
};
using RH1 = RollingHash<(int)1e9 + 7>;
using RH2 = RollingHash<(int)1e9 + 9>;
using RH = pair<RH1, RH2>;
using H = pair<uint_fast64_t, uint_fast64_t>;
RH init(const string &s) { return make_pair(RH1(s), RH2(s)); }
H get(RH &rh, int l, int r) { return make_pair(rh.first.get(l, r), rh.second.get(l, r)); }
H rotate(RH &rh, int n, int sz) { return make_pair(rh.first.rotate(n, sz), rh.second.rotate(n, sz)); }
