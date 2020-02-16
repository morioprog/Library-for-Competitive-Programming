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


# :warning: Math/Fraction.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Fraction.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 01:36:10+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T> struct Fraction {
    T numer, denom;
    T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
    Fraction(T n = 0, T d = 1) {
        T g = gcd(n, d);
        assert(d != 0);
        numer = n / g, denom = d / g;
        if (denom < 0) numer *= -1, denom *= -1;
    }
    Fraction operator+(const Fraction &f) const { return Fraction(numer * f.denom + denom * f.numer, denom * f.denom); }
    Fraction operator-(const Fraction &f) const { return Fraction(numer * f.denom - denom * f.numer, denom * f.denom); }
    Fraction operator*(const Fraction &f) const { return Fraction(numer * f.numer, denom * f.denom); }
    Fraction operator/(const Fraction &f) const { return Fraction(numer * f.denom, denom * f.numer); }
    Fraction &operator+=(const Fraction &f) { return *this = *this + f; }
    Fraction &operator-=(const Fraction &f) { return *this = *this - f; }
    Fraction &operator*=(const Fraction &f) { return *this = *this * f; }
    Fraction &operator/=(const Fraction &f) { return *this = *this / f; }
    Fraction operator~() const { return Fraction(denom, numer); }
    bool operator==(const Fraction &f) const { return numer == f.numer and denom == f.denom; }
    bool operator!=(const Fraction &f) const { return numer != f.numer  or denom != f.denom; }
    bool operator< (const Fraction &f) const { return numer * f.denom <  f.numer * denom; }
    bool operator<=(const Fraction &f) const { return numer * f.denom <= f.numer * denom; }
    bool operator> (const Fraction &f) const { return numer * f.denom >  f.numer * denom; }
    bool operator>=(const Fraction &f) const { return numer * f.denom >= f.numer * denom; }
    explicit operator T()      const { assert(denom == 1); return numer; }
    explicit operator double() const { return (double) numer / denom; }
    friend ostream &operator<<(ostream &os, const Fraction <T> &f) {
        return os << f.numer << " / " << f.denom;
    }
};

/*
・Fraction
[備考] 分数演算のための構造体
[使用例]
Fraction<int> f(2, 6);      // 2/6 = 1/3の値を持つ
double(f);                  // 0.3333333
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/Fraction.cpp"
template<typename T> struct Fraction {
    T numer, denom;
    T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
    Fraction(T n = 0, T d = 1) {
        T g = gcd(n, d);
        assert(d != 0);
        numer = n / g, denom = d / g;
        if (denom < 0) numer *= -1, denom *= -1;
    }
    Fraction operator+(const Fraction &f) const { return Fraction(numer * f.denom + denom * f.numer, denom * f.denom); }
    Fraction operator-(const Fraction &f) const { return Fraction(numer * f.denom - denom * f.numer, denom * f.denom); }
    Fraction operator*(const Fraction &f) const { return Fraction(numer * f.numer, denom * f.denom); }
    Fraction operator/(const Fraction &f) const { return Fraction(numer * f.denom, denom * f.numer); }
    Fraction &operator+=(const Fraction &f) { return *this = *this + f; }
    Fraction &operator-=(const Fraction &f) { return *this = *this - f; }
    Fraction &operator*=(const Fraction &f) { return *this = *this * f; }
    Fraction &operator/=(const Fraction &f) { return *this = *this / f; }
    Fraction operator~() const { return Fraction(denom, numer); }
    bool operator==(const Fraction &f) const { return numer == f.numer and denom == f.denom; }
    bool operator!=(const Fraction &f) const { return numer != f.numer  or denom != f.denom; }
    bool operator< (const Fraction &f) const { return numer * f.denom <  f.numer * denom; }
    bool operator<=(const Fraction &f) const { return numer * f.denom <= f.numer * denom; }
    bool operator> (const Fraction &f) const { return numer * f.denom >  f.numer * denom; }
    bool operator>=(const Fraction &f) const { return numer * f.denom >= f.numer * denom; }
    explicit operator T()      const { assert(denom == 1); return numer; }
    explicit operator double() const { return (double) numer / denom; }
    friend ostream &operator<<(ostream &os, const Fraction <T> &f) {
        return os << f.numer << " / " << f.denom;
    }
};

/*
・Fraction
[備考] 分数演算のための構造体
[使用例]
Fraction<int> f(2, 6);      // 2/6 = 1/3の値を持つ
double(f);                  // 0.3333333
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

