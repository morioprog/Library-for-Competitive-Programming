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


# :warning: Other/LimitInt.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6311ae17c1ee52b36e68aaf4ad066387">Other</a>
* <a href="{{ site.github.repository_url }}/blob/master/Other/LimitInt.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-10 12:53:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T> struct LimitInt {
    T x;
    const T low, high;
    T get() const { return x; }
    LimitInt() : x(0), low(numeric_limits< T >::min() + 10), high(numeric_limits< T >::max() - 10) {}
    LimitInt(const T &x) : x(x), low(numeric_limits< T >::min() + 10), high(numeric_limits< T >::max() - 10) {}
    LimitInt& operator+=(const LimitInt &y) { x = (double) x + y.x > high ? high : x + y.x; return (*this); }
    LimitInt& operator-=(const LimitInt &y) { x = (double) x - y.x <  low ?  low : x - y.x; return (*this); }
    LimitInt& operator*=(const LimitInt &y) { x = (double) x * y.x > high ? high : x * y.x; return (*this); }
    LimitInt& operator/=(const LimitInt &y) { x /= y.x;                                     return (*this); }
    LimitInt operator-() const { return -x; }
    LimitInt operator+(const LimitInt &y) const { LimitInt ret(x); ret += y; return ret; }
    LimitInt operator-(const LimitInt &y) const { LimitInt ret(x); ret -= y; return ret; }
    LimitInt operator*(const LimitInt &y) const { LimitInt ret(x); ret *= y; return ret; }
    LimitInt operator/(const LimitInt &y) const { LimitInt ret(*this); ret /= y; return ret; }
    LimitInt operator==(const LimitInt &y) const { return (x == y.x); }
    LimitInt operator!=(const LimitInt &y) const { return (x != y.x); }
    LimitInt operator< (const LimitInt &y) const { return (x <  y.x); }
    LimitInt operator> (const LimitInt &y) const { return (x >  y.x); }
    LimitInt operator<=(const LimitInt &y) const { return (x <= y.x); }
    LimitInt operator>=(const LimitInt &y) const { return (x >= y.x); }
};

/*
・LimitInt
[備考] 加減乗除の演算に対して, 値の上限と下限を設定する
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Other/LimitInt.cpp"
template<typename T> struct LimitInt {
    T x;
    const T low, high;
    T get() const { return x; }
    LimitInt() : x(0), low(numeric_limits< T >::min() + 10), high(numeric_limits< T >::max() - 10) {}
    LimitInt(const T &x) : x(x), low(numeric_limits< T >::min() + 10), high(numeric_limits< T >::max() - 10) {}
    LimitInt& operator+=(const LimitInt &y) { x = (double) x + y.x > high ? high : x + y.x; return (*this); }
    LimitInt& operator-=(const LimitInt &y) { x = (double) x - y.x <  low ?  low : x - y.x; return (*this); }
    LimitInt& operator*=(const LimitInt &y) { x = (double) x * y.x > high ? high : x * y.x; return (*this); }
    LimitInt& operator/=(const LimitInt &y) { x /= y.x;                                     return (*this); }
    LimitInt operator-() const { return -x; }
    LimitInt operator+(const LimitInt &y) const { LimitInt ret(x); ret += y; return ret; }
    LimitInt operator-(const LimitInt &y) const { LimitInt ret(x); ret -= y; return ret; }
    LimitInt operator*(const LimitInt &y) const { LimitInt ret(x); ret *= y; return ret; }
    LimitInt operator/(const LimitInt &y) const { LimitInt ret(*this); ret /= y; return ret; }
    LimitInt operator==(const LimitInt &y) const { return (x == y.x); }
    LimitInt operator!=(const LimitInt &y) const { return (x != y.x); }
    LimitInt operator< (const LimitInt &y) const { return (x <  y.x); }
    LimitInt operator> (const LimitInt &y) const { return (x >  y.x); }
    LimitInt operator<=(const LimitInt &y) const { return (x <= y.x); }
    LimitInt operator>=(const LimitInt &y) const { return (x >= y.x); }
};

/*
・LimitInt
[備考] 加減乗除の演算に対して, 値の上限と下限を設定する
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

