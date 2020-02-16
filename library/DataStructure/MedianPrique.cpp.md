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


# :warning: DataStructure/MedianPrique.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/MedianPrique.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 02:30:07+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T> struct MedianPrique {
    priority_queue<T> L;
    priority_queue<T, vector<T>, greater<>> R;
    int sz;
    T L_sum, R_sum;
    MedianPrique() : sz(0), L_sum(0LL), R_sum(0LL) {}
    void L_push(T val) { L_sum += val; L.push(val); ++sz; }
    void L_pop()       { L_sum -= L.top(); L.pop(); --sz; }
    void R_push(T val) { R_sum += val; R.push(val); ++sz; }
    void R_pop()       { R_sum -= R.top(); R.pop(); --sz; }
    void push(T val) {
        if (sz == 0) L_push(val);
        else if (sz % 2 == 1) {
            T tp = L.top();
            if (tp > val) { L_pop(); L_push(val); R_push(tp); }
            else { R_push(val); }
        } else {
            T tp = R.top();
            if (val > tp) { R_pop(); R_push(val); L_push(tp); }
            else { L_push(val); }
        }
    }
    T getMedian(bool needtobeodd = true) {
        if (sz % 2 == 1) return L.top();
        assert(!needtobeodd);
        return (L.top() + R.top()) / 2;
    }
    T getMinimumDifference() {
        int L_sz = (sz + 1) / 2;
        int R_sz = sz / 2;
        T med = L.top();
        return (R_sum - med * R_sz) + (med * L_sz - L_sum);
    }
};

/*
・MedianPrique
[備考] priority_queue2本で中央値を管理するやつ
[使用例]
MedianPrique<long long> mpq;    // long longで定義
mpq.push(val);                  // valをpush
mpq.getMedian();                // 中央値を取得 (要素が奇数個じゃなかったらassert)
mpq.getMedian(false);           // 中央値を取得 (要素が偶数個だったら平均を返す)
mpq.L.top();                    // 全要素との絶対値の総和を最小化する数
mpq.getMinimumDifference();     // 全要素との絶対値の総和の最小値
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/MedianPrique.cpp"
template<typename T> struct MedianPrique {
    priority_queue<T> L;
    priority_queue<T, vector<T>, greater<>> R;
    int sz;
    T L_sum, R_sum;
    MedianPrique() : sz(0), L_sum(0LL), R_sum(0LL) {}
    void L_push(T val) { L_sum += val; L.push(val); ++sz; }
    void L_pop()       { L_sum -= L.top(); L.pop(); --sz; }
    void R_push(T val) { R_sum += val; R.push(val); ++sz; }
    void R_pop()       { R_sum -= R.top(); R.pop(); --sz; }
    void push(T val) {
        if (sz == 0) L_push(val);
        else if (sz % 2 == 1) {
            T tp = L.top();
            if (tp > val) { L_pop(); L_push(val); R_push(tp); }
            else { R_push(val); }
        } else {
            T tp = R.top();
            if (val > tp) { R_pop(); R_push(val); L_push(tp); }
            else { L_push(val); }
        }
    }
    T getMedian(bool needtobeodd = true) {
        if (sz % 2 == 1) return L.top();
        assert(!needtobeodd);
        return (L.top() + R.top()) / 2;
    }
    T getMinimumDifference() {
        int L_sz = (sz + 1) / 2;
        int R_sz = sz / 2;
        T med = L.top();
        return (R_sum - med * R_sz) + (med * L_sz - L_sum);
    }
};

/*
・MedianPrique
[備考] priority_queue2本で中央値を管理するやつ
[使用例]
MedianPrique<long long> mpq;    // long longで定義
mpq.push(val);                  // valをpush
mpq.getMedian();                // 中央値を取得 (要素が奇数個じゃなかったらassert)
mpq.getMedian(false);           // 中央値を取得 (要素が偶数個だったら平均を返す)
mpq.L.top();                    // 全要素との絶対値の総和を最小化する数
mpq.getMinimumDifference();     // 全要素との絶対値の総和の最小値
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

