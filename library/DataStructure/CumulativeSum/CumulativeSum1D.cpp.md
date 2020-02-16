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


# :warning: DataStructure/CumulativeSum/CumulativeSum1D.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#767aa3a8651144736ca7f91920f93f07">DataStructure/CumulativeSum</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/CumulativeSum/CumulativeSum1D.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 01:49:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T = long long> struct CumulativeSum {
    vector< T > data;
    CumulativeSum(int sz, T init = 0) : data(sz, init) {}
    void add(int k, T x) {
        data[k] += x;
        // data[k] ^= x;
    }
    void build() {
        for (int i = 1; i < (int)data.size(); ++i) {
            data[i] += data[i - 1];
            // data[i] ^= data[i - 1];
        }
    }
    T query(int k) {
        if (k < 0) return 0;
        return data[min(k, (int)data.size() - 1)];
    }
    T query(int l, int r) {
        if (l >= r) return 0;
        T ret = (data[min(r - 1, (int)data.size() - 1)]);
        if (l > 0) ret -= (data[min(l - 1, (int)data.size() - 1)]);
        // if (l > 0) ret ^= (data[min(l - 1, (int)data.size() - 1)]);
        return ret;
    }
    T operator[](const int &k) {
        return data[k];
    }
    void print() {
        for (int i = 0; i < (int)data.size(); ++i) cerr << data[i] << ' ';
        cerr << endl;
    }
};

/*
・1次元累積和
    >     build O(N)
    > add,query O(1)
[応用例] 加減算をそれぞれXORにすると, 累積XOR
[使用例]
CumulativeSum<int> acc(N);  // 要素数Nの累積和用の配列
acc.add(k, x);              // 要素kに値xを加える
acc.build();                // 累積和を取る
acc.query(k);               // 閉区間[0, k]の和
acc.query(l, r);            // 半開区間[l, r)の和
acc[k];                     // 要素kを取得
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/CumulativeSum/CumulativeSum1D.cpp"
template<typename T = long long> struct CumulativeSum {
    vector< T > data;
    CumulativeSum(int sz, T init = 0) : data(sz, init) {}
    void add(int k, T x) {
        data[k] += x;
        // data[k] ^= x;
    }
    void build() {
        for (int i = 1; i < (int)data.size(); ++i) {
            data[i] += data[i - 1];
            // data[i] ^= data[i - 1];
        }
    }
    T query(int k) {
        if (k < 0) return 0;
        return data[min(k, (int)data.size() - 1)];
    }
    T query(int l, int r) {
        if (l >= r) return 0;
        T ret = (data[min(r - 1, (int)data.size() - 1)]);
        if (l > 0) ret -= (data[min(l - 1, (int)data.size() - 1)]);
        // if (l > 0) ret ^= (data[min(l - 1, (int)data.size() - 1)]);
        return ret;
    }
    T operator[](const int &k) {
        return data[k];
    }
    void print() {
        for (int i = 0; i < (int)data.size(); ++i) cerr << data[i] << ' ';
        cerr << endl;
    }
};

/*
・1次元累積和
    >     build O(N)
    > add,query O(1)
[応用例] 加減算をそれぞれXORにすると, 累積XOR
[使用例]
CumulativeSum<int> acc(N);  // 要素数Nの累積和用の配列
acc.add(k, x);              // 要素kに値xを加える
acc.build();                // 累積和を取る
acc.query(k);               // 閉区間[0, k]の和
acc.query(l, r);            // 半開区間[l, r)の和
acc[k];                     // 要素kを取得
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

