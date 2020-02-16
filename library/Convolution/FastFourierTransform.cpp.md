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


# :warning: Convolution/FastFourierTransform.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#fa0f0ae43fdca46d1d68255409ec0b89">Convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/Convolution/FastFourierTransform.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 01:49:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
namespace FastFourierTransform {
    using C = complex< double >;
    void DiscreteFourierTransform(vector< C > &F, bool rev) {
        const int N = (int)F.size();
        const double PI = (rev ? -1 : 1) * acos(-1);
        for (int i = 0, j = 1; j + 1 < N; ++j) {
            for (int k = N >> 1; k > (i ^= k); k >>= 1);
            if (i > j) swap(F[i], F[j]);
        }
        C w, s, t;
        for (int i = 1; i < N; i <<= 1) {
            for (int k = 0; k < i; ++k) {
                w = polar(1.0, PI / i * k);
                for (int j = 0; j < N; j += i * 2) {
                    s = F[j + k];
                    t = C(
                        F[j + k + i].real() * w.real() - F[j + k + i].imag() * w.imag(),
                        F[j + k + i].real() * w.imag() + F[j + k + i].imag() * w.real()
                    );
                    F[j + k] = s + t, F[j + k + i] = s - t;
                }
            }
        }
        if (rev) for (int i = 0; i < N; ++i) F[i] /= N;
    }
    vector<long long> Multiply(const vector<int> &A, const vector<int> &B) {
        int sz = 1;
        while (sz < A.size() + B.size() - 1) sz <<= 1;
        vector< C > F(sz), G(sz);
        for (int i = 0; i < A.size(); ++i) F[i] = A[i];
        for (int i = 0; i < B.size(); ++i) G[i] = B[i];
        DiscreteFourierTransform(F, false);
        DiscreteFourierTransform(G, false);
        for (int i = 0; i < sz; ++i) F[i] *= G[i];
        DiscreteFourierTransform(F, true);
        vector<long long> X(A.size() + B.size() - 1);
        for (int i = 0; i < A.size() + B.size() - 1; ++i) X[i] = F[i].real() + 0.5;
        return X;
    }
};

/*
・高速フーリエ変換
    > O(NlogN)
[備考] 畳み込み(c_i = Sum[j = 0..i] a_j * b_(i - j))を高速に行える.
[使用例] vector<long long> C = FastFourierTransform::Multiply(A, B);      // AとBの畳み込みの結果をCに代入
[参考] https://www.creativ.xyz/fast-fourier-transform/
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Convolution/FastFourierTransform.cpp"
namespace FastFourierTransform {
    using C = complex< double >;
    void DiscreteFourierTransform(vector< C > &F, bool rev) {
        const int N = (int)F.size();
        const double PI = (rev ? -1 : 1) * acos(-1);
        for (int i = 0, j = 1; j + 1 < N; ++j) {
            for (int k = N >> 1; k > (i ^= k); k >>= 1);
            if (i > j) swap(F[i], F[j]);
        }
        C w, s, t;
        for (int i = 1; i < N; i <<= 1) {
            for (int k = 0; k < i; ++k) {
                w = polar(1.0, PI / i * k);
                for (int j = 0; j < N; j += i * 2) {
                    s = F[j + k];
                    t = C(
                        F[j + k + i].real() * w.real() - F[j + k + i].imag() * w.imag(),
                        F[j + k + i].real() * w.imag() + F[j + k + i].imag() * w.real()
                    );
                    F[j + k] = s + t, F[j + k + i] = s - t;
                }
            }
        }
        if (rev) for (int i = 0; i < N; ++i) F[i] /= N;
    }
    vector<long long> Multiply(const vector<int> &A, const vector<int> &B) {
        int sz = 1;
        while (sz < A.size() + B.size() - 1) sz <<= 1;
        vector< C > F(sz), G(sz);
        for (int i = 0; i < A.size(); ++i) F[i] = A[i];
        for (int i = 0; i < B.size(); ++i) G[i] = B[i];
        DiscreteFourierTransform(F, false);
        DiscreteFourierTransform(G, false);
        for (int i = 0; i < sz; ++i) F[i] *= G[i];
        DiscreteFourierTransform(F, true);
        vector<long long> X(A.size() + B.size() - 1);
        for (int i = 0; i < A.size() + B.size() - 1; ++i) X[i] = F[i].real() + 0.5;
        return X;
    }
};

/*
・高速フーリエ変換
    > O(NlogN)
[備考] 畳み込み(c_i = Sum[j = 0..i] a_j * b_(i - j))を高速に行える.
[使用例] vector<long long> C = FastFourierTransform::Multiply(A, B);      // AとBの畳み込みの結果をCに代入
[参考] https://www.creativ.xyz/fast-fourier-transform/
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

