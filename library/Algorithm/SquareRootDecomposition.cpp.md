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


# :warning: Algorithm/SquareRootDecomposition.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4afa80e77a07f7488ce4d1bdd8c4977a">Algorithm</a>
* <a href="{{ site.github.repository_url }}/blob/master/Algorithm/SquareRootDecomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-19 21:08:51+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
const int bucketSize = 400
function<int(int, int)> query = [&](int l, int r) {
    int ret = 0;
    for (int x = l; x < r;) {
        int bi = x / bucketSize;
        if (l <= bi * bucketSize and (bi + 1) * bucketSize <= r) {
            // バケット
            x += bucketSize;
        } else {
            // 余った部分
            ++x;
        }
    }
    return ret;
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Algorithm/SquareRootDecomposition.cpp"
const int bucketSize = 400
function<int(int, int)> query = [&](int l, int r) {
    int ret = 0;
    for (int x = l; x < r;) {
        int bi = x / bucketSize;
        if (l <= bi * bucketSize and (bi + 1) * bucketSize <= r) {
            // バケット
            x += bucketSize;
        } else {
            // 余った部分
            ++x;
        }
    }
    return ret;
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

