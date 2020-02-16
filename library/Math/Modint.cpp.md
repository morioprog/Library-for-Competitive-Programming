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


# :warning: Math/Modint.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Modint.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 01:49:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template< int MODULO > struct ModInt {
    using int64 = long long;
    using uint32 = unsigned int;
    using uint64 = unsigned long long;
    uint64 x; ModInt() : x(0) {}
    ModInt(int64 y) : x(set(y % MODULO + MODULO)) {}
    static uint64 set(const int64 &y) { return (y < MODULO) ? y : y - MODULO; }
    static ModInt make(const uint64 &y) { ModInt ret = y; return ret; }
    ModInt operator+(const ModInt &m) const { return make(set(x + m.x)); }
    ModInt operator-(const ModInt &m) const { return make(set(x + MODULO - m.x)); }
    ModInt operator*(const ModInt &m) const { return make(x * m.x % MODULO); }
    ModInt operator/(const ModInt &m) const { return make(x) * ~make(m.x); }
    ModInt &operator+=(const ModInt &m) { return *this = *this + m; }
    ModInt &operator-=(const ModInt &m) { return *this = *this - m; }
    ModInt &operator*=(const ModInt &m) { return *this = *this * m; }
    ModInt &operator/=(const ModInt &m) { return *this = *this / m; }
    ModInt &operator^=(const uint64 &y) { return *this = *this ^ y; }
    ModInt operator~ () const { return *this ^ (MODULO - 2); }
    ModInt operator- () const { return make(set(MODULO - x)); }
    ModInt operator! () const { return getFact(uint32(*this)); }
    ModInt operator& () const { return getFinv(uint32(*this)); }
    ModInt operator++() { return *this = make(set(x + 1)); }
    ModInt operator--() { return *this = make(set(x + MODULO - 1)); }
    bool operator==(const ModInt &m) const { return x == m.x; }
    bool operator!=(const ModInt &m) const { return x != m.x; }
    bool operator< (const ModInt &m) const { return x <  m.x; }
    bool operator<=(const ModInt &m) const { return x <= m.x; }
    bool operator> (const ModInt &m) const { return x >  m.x; }
    bool operator>=(const ModInt &m) const { return x >= m.x; }
    explicit operator   bool() const { return x; }
    explicit operator uint64() const { return x; }
    ModInt operator^(uint64 y) const {
        uint64 t = x, u = 1;
        while (y) { if (y & 1) (u *= t) %= MODULO; (t *= t) %= MODULO; y >>= 1; }
        return make(u);
    }
    friend ostream &operator<<(ostream &os, const ModInt< MODULO > &m) { return os << m.x; }
    friend istream &operator>>(istream &is, ModInt< MODULO > &m) { uint64 y; is >> y; m = make(y); return is; }
    static vector< ModInt > fact, finv, invs;
    static void init(uint32 n) {
        uint32 m = fact.size();
        if (n < m) return;
        fact.resize(n + 1, 1);
        finv.resize(n + 1, 1);
        invs.resize(n + 1, 1);
        if (m == 0) m = 1;
        for (uint32 i = m; i <= n; ++i) fact[i] = fact[i - 1] * ModInt(i);
        finv[n] = ModInt(1) / fact[n];
        for (uint32 i = n; i >= m; --i) finv[i - 1] = finv[i] * make(i);
        for (uint32 i = m; i <= n; ++i) invs[i] = finv[i] * fact[i - 1];
    }
    static ModInt getFact(uint32 n) { init(n); return fact[n]; }
    static ModInt getFinv(uint32 n) { init(n); return finv[n]; }
    static ModInt getInvs(uint32 n) { init(n); return invs[n]; }
    static ModInt C(int64 n, int64 r) {
        if (r == 0) return make(1);
        if (r <  0) return make(0);
        if (n <  0) return make(r & 1 ? MODULO - 1 : 1) * C(-n + r - 1, r);
        if (n == 0 || n < r) return make(0);
        init(n);
        return fact[n] * finv[n - r] * finv[r];
    }
    static ModInt P(int64 n, int64 r) {
        if (n < r || r < 0) return make(0);
        init(n);
        return fact[n] * finv[n - r];
    }
    static ModInt H(int64 n, int64 r) {
        if (n < 0 || r < 0) return make(0);
        if (!n && !r) return make(1);
        init(n + r - 1);
        return C(n + r - 1, r);
    }
    static ModInt montmort(uint32 n) {
        ModInt res;
        init(n);
        for (uint32 k = 2; k <= n; ++k) {
            if (k & 1) res -= finv[k];
            else res += finv[k];
        }
        return res *= fact[n];
    }
    static ModInt LagrangePolynomial(vector<ModInt> &y, ModInt t) {
        uint32 n = y.size() - 1;
        if (t.x <= n) return y[t.x];
        init(n + 1);
        ModInt res, num(1);
        for (uint32 i = 0; i <= n; ++i) num *= t - make(i);
        for (uint32 i = 0; i <= n; ++i) {
            ModInt tmp = y[i] * num / (t - make(i)) * finv[i] * finv[n - i];
            if ((n - i) & 1) res -= tmp;
            else res += tmp;
        }
        return res;
    }
};
template< int MODULO >
vector<ModInt< MODULO >> ModInt< MODULO >::fact = vector<ModInt< MODULO >>();
template< int MODULO >
vector<ModInt< MODULO >> ModInt< MODULO >::finv = vector<ModInt< MODULO >>();
template< int MODULO >
vector<ModInt< MODULO >> ModInt< MODULO >::invs = vector<ModInt< MODULO >>();
using modint = ModInt< MOD >;

/*
・ModInt
[備考] Mod演算のための構造体
[使用例]
modint M;           // 剰余系MOD(1e9+7)における演算ができる
ModInt<mod> N;      // 剰余系modにおける演算ができる
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/Modint.cpp"
template< int MODULO > struct ModInt {
    using int64 = long long;
    using uint32 = unsigned int;
    using uint64 = unsigned long long;
    uint64 x; ModInt() : x(0) {}
    ModInt(int64 y) : x(set(y % MODULO + MODULO)) {}
    static uint64 set(const int64 &y) { return (y < MODULO) ? y : y - MODULO; }
    static ModInt make(const uint64 &y) { ModInt ret = y; return ret; }
    ModInt operator+(const ModInt &m) const { return make(set(x + m.x)); }
    ModInt operator-(const ModInt &m) const { return make(set(x + MODULO - m.x)); }
    ModInt operator*(const ModInt &m) const { return make(x * m.x % MODULO); }
    ModInt operator/(const ModInt &m) const { return make(x) * ~make(m.x); }
    ModInt &operator+=(const ModInt &m) { return *this = *this + m; }
    ModInt &operator-=(const ModInt &m) { return *this = *this - m; }
    ModInt &operator*=(const ModInt &m) { return *this = *this * m; }
    ModInt &operator/=(const ModInt &m) { return *this = *this / m; }
    ModInt &operator^=(const uint64 &y) { return *this = *this ^ y; }
    ModInt operator~ () const { return *this ^ (MODULO - 2); }
    ModInt operator- () const { return make(set(MODULO - x)); }
    ModInt operator! () const { return getFact(uint32(*this)); }
    ModInt operator& () const { return getFinv(uint32(*this)); }
    ModInt operator++() { return *this = make(set(x + 1)); }
    ModInt operator--() { return *this = make(set(x + MODULO - 1)); }
    bool operator==(const ModInt &m) const { return x == m.x; }
    bool operator!=(const ModInt &m) const { return x != m.x; }
    bool operator< (const ModInt &m) const { return x <  m.x; }
    bool operator<=(const ModInt &m) const { return x <= m.x; }
    bool operator> (const ModInt &m) const { return x >  m.x; }
    bool operator>=(const ModInt &m) const { return x >= m.x; }
    explicit operator   bool() const { return x; }
    explicit operator uint64() const { return x; }
    ModInt operator^(uint64 y) const {
        uint64 t = x, u = 1;
        while (y) { if (y & 1) (u *= t) %= MODULO; (t *= t) %= MODULO; y >>= 1; }
        return make(u);
    }
    friend ostream &operator<<(ostream &os, const ModInt< MODULO > &m) { return os << m.x; }
    friend istream &operator>>(istream &is, ModInt< MODULO > &m) { uint64 y; is >> y; m = make(y); return is; }
    static vector< ModInt > fact, finv, invs;
    static void init(uint32 n) {
        uint32 m = fact.size();
        if (n < m) return;
        fact.resize(n + 1, 1);
        finv.resize(n + 1, 1);
        invs.resize(n + 1, 1);
        if (m == 0) m = 1;
        for (uint32 i = m; i <= n; ++i) fact[i] = fact[i - 1] * ModInt(i);
        finv[n] = ModInt(1) / fact[n];
        for (uint32 i = n; i >= m; --i) finv[i - 1] = finv[i] * make(i);
        for (uint32 i = m; i <= n; ++i) invs[i] = finv[i] * fact[i - 1];
    }
    static ModInt getFact(uint32 n) { init(n); return fact[n]; }
    static ModInt getFinv(uint32 n) { init(n); return finv[n]; }
    static ModInt getInvs(uint32 n) { init(n); return invs[n]; }
    static ModInt C(int64 n, int64 r) {
        if (r == 0) return make(1);
        if (r <  0) return make(0);
        if (n <  0) return make(r & 1 ? MODULO - 1 : 1) * C(-n + r - 1, r);
        if (n == 0 || n < r) return make(0);
        init(n);
        return fact[n] * finv[n - r] * finv[r];
    }
    static ModInt P(int64 n, int64 r) {
        if (n < r || r < 0) return make(0);
        init(n);
        return fact[n] * finv[n - r];
    }
    static ModInt H(int64 n, int64 r) {
        if (n < 0 || r < 0) return make(0);
        if (!n && !r) return make(1);
        init(n + r - 1);
        return C(n + r - 1, r);
    }
    static ModInt montmort(uint32 n) {
        ModInt res;
        init(n);
        for (uint32 k = 2; k <= n; ++k) {
            if (k & 1) res -= finv[k];
            else res += finv[k];
        }
        return res *= fact[n];
    }
    static ModInt LagrangePolynomial(vector<ModInt> &y, ModInt t) {
        uint32 n = y.size() - 1;
        if (t.x <= n) return y[t.x];
        init(n + 1);
        ModInt res, num(1);
        for (uint32 i = 0; i <= n; ++i) num *= t - make(i);
        for (uint32 i = 0; i <= n; ++i) {
            ModInt tmp = y[i] * num / (t - make(i)) * finv[i] * finv[n - i];
            if ((n - i) & 1) res -= tmp;
            else res += tmp;
        }
        return res;
    }
};
template< int MODULO >
vector<ModInt< MODULO >> ModInt< MODULO >::fact = vector<ModInt< MODULO >>();
template< int MODULO >
vector<ModInt< MODULO >> ModInt< MODULO >::finv = vector<ModInt< MODULO >>();
template< int MODULO >
vector<ModInt< MODULO >> ModInt< MODULO >::invs = vector<ModInt< MODULO >>();
using modint = ModInt< MOD >;

/*
・ModInt
[備考] Mod演算のための構造体
[使用例]
modint M;           // 剰余系MOD(1e9+7)における演算ができる
ModInt<mod> N;      // 剰余系modにおける演算ができる
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

