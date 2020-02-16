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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: Math/Prime/Divisor.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#231e1df35934043e4793dedc0bd652e6">Math/Prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Prime/Divisor.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 01:49:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/Prime/Divisor.cpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

