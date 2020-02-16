---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: String/RollingHash.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#27118326006d3829667a400ad23d5d98">String</a>
* <a href="{{ site.github.repository_url }}/blob/master/String/RollingHash.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 01:49:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<int mod, int base=10007>
struct RollingHash {
    vector<unsigned long long> hsh, pwr;
    unsigned long long umod(unsigned long long n) { return (n % mod + mod) % mod; }
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
    unsigned long long get(int l, int r) {
        return umod(hsh[r] - hsh[l] * pwr[r - l]);
    }
    // h1 <- h2
    unsigned long long join(unsigned long long h1, unsigned long long h2, int h2_sz) {
        return umod(h1 * pwr[h2_sz] + h2);
    }
    // [idx, len_s) + [0, idx)
    unsigned long long rotate(unsigned long long idx, int len_s) {
        return join(get(idx, len_s), get(0, idx), idx);
    }
};
using RH1 = RollingHash<(int)1e9 + 7>;
using RH2 = RollingHash<(int)1e9 + 9>;
using RH = pair<RH1, RH2>;
using H = pair<unsigned long long, unsigned long long>;
RH init(const string &s) { return make_pair(RH1(s), RH2(s)); }
H get(RH &rh, int l, int r) { return make_pair(rh.first.get(l, r), rh.second.get(l, r)); }
H rotate(RH &rh, int n, int sz) { return make_pair(rh.first.rotate(n, sz), rh.second.rotate(n, sz)); }

/*
・ローリングハッシュ
[備考] 文字列をハッシュとして管理する. ハッシュ値の衝突に注意.
[使用例]
RH rh = init(S);            // 文字列Sでハッシュを構築
get(rh, l, r);              // 半開区間[l, r)のハッシュ値を取得
rotate(rh, idx, len_s);     // 文字列をidxの位置でrotateしたものを返す
[ToDo] 回文判定
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "String/RollingHash.cpp"
template<int mod, int base=10007>
struct RollingHash {
    vector<unsigned long long> hsh, pwr;
    unsigned long long umod(unsigned long long n) { return (n % mod + mod) % mod; }
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
    unsigned long long get(int l, int r) {
        return umod(hsh[r] - hsh[l] * pwr[r - l]);
    }
    // h1 <- h2
    unsigned long long join(unsigned long long h1, unsigned long long h2, int h2_sz) {
        return umod(h1 * pwr[h2_sz] + h2);
    }
    // [idx, len_s) + [0, idx)
    unsigned long long rotate(unsigned long long idx, int len_s) {
        return join(get(idx, len_s), get(0, idx), idx);
    }
};
using RH1 = RollingHash<(int)1e9 + 7>;
using RH2 = RollingHash<(int)1e9 + 9>;
using RH = pair<RH1, RH2>;
using H = pair<unsigned long long, unsigned long long>;
RH init(const string &s) { return make_pair(RH1(s), RH2(s)); }
H get(RH &rh, int l, int r) { return make_pair(rh.first.get(l, r), rh.second.get(l, r)); }
H rotate(RH &rh, int n, int sz) { return make_pair(rh.first.rotate(n, sz), rh.second.rotate(n, sz)); }

/*
・ローリングハッシュ
[備考] 文字列をハッシュとして管理する. ハッシュ値の衝突に注意.
[使用例]
RH rh = init(S);            // 文字列Sでハッシュを構築
get(rh, l, r);              // 半開区間[l, r)のハッシュ値を取得
rotate(rh, idx, len_s);     // 文字列をidxの位置でrotateしたものを返す
[ToDo] 回文判定
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

