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


# :warning: Math/Matrix/Matrix.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#f6ce61238330a8f48f1ec7555e6c8ca5">Math/Matrix</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Matrix/Matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-10 12:53:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template< class T > struct Matrix {
    vector< vector< T > > A;
    Matrix() {}
    Matrix(size_t n, size_t m) : A(n, vector< T >(m, 0)) {}
    Matrix(size_t n) : A(n, vector< T >(n, 0)) {};
    size_t height() const { return (A.size()); }
    size_t  width() const { return (A[0].size()); }
    inline const vector< T > &operator[](int k) const { return (A.at(k)); }
    inline       vector< T > &operator[](int k)       { return (A.at(k)); }
    static Matrix I(size_t n) {
        Matrix mat(n);
        for (int i = 0; i < n; ++i) mat[i][i] = 1;
        return (mat);
    }
    Matrix& operator+=(const Matrix &B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                (*this)[i][j] += B[i][j];
        return (*this);
    }
    Matrix& operator-=(const Matrix &B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                (*this)[i][j] -= B[i][j];
        return (*this);
    }
    Matrix& operator*=(const Matrix &B) {
        size_t n = height(), m = B.width(), p = width();
        assert(p == B.height());
        vector< vector< T > > C(n, vector< T >(m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int k = 0; k < p; k++)
                    C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
        A.swap(C);
        return (*this);
    }
    Matrix& operator^=(long long k) {
        Matrix B = Matrix::I(height());
        while (k > 0) {
            if (k & 1) B *= *this;
            *this *= *this;
            k >>= 1LL;
        }
        A.swap(B.A);
        return *this;
    }
    Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }
    Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }
    Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }
    Matrix operator^(const long long k) const { return (Matrix(*this) ^= k); }
    friend ostream &operator<<(ostream &os, Matrix &p) {
        size_t n = p.height(), m = p.width();
        for (int i = 0; i < n; i++) {
            os << '[';
            for (int j = 0; j < m; j++) {
                os << p[i][j] << (j + 1 == m ? "]\n" : ',');
            }
        }
        return os;
    }
    T determinant() {
        Matrix B(*this);
        assert(width() == height());
        T ret = 1;
        for (int i = 0; i < width(); i++) {
            int idx = -1;
            for (int j = i; j < width(); j++) if (B[j][i] != 0) idx = j;
            if (idx == -1) return (0);
            if (i != idx) { ret *= -1; swap(B[i], B[idx]); }
            ret *= B[i][i];
            T vv = B[i][i];
            for (int j = 0; j < width(); j++) B[i][j] /= vv;
            for (int j = i + 1; j < width(); j++) {
                T a = B[j][i];
                for (int k = 0; k < width(); k++) B[j][k] -= B[i][k] * a;
            }
        }
        return ret;
    }
};

/*
・行列演算
[使用例]
Matrix<int> mat(n,m);   // n行m列の行列を定義
mat[i][j];              // i行j列目の要素を取得
mat.determinant();      // matの行列式を計算
mat ^= k;               // matのk乗を計算
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/Matrix/Matrix.cpp"
template< class T > struct Matrix {
    vector< vector< T > > A;
    Matrix() {}
    Matrix(size_t n, size_t m) : A(n, vector< T >(m, 0)) {}
    Matrix(size_t n) : A(n, vector< T >(n, 0)) {};
    size_t height() const { return (A.size()); }
    size_t  width() const { return (A[0].size()); }
    inline const vector< T > &operator[](int k) const { return (A.at(k)); }
    inline       vector< T > &operator[](int k)       { return (A.at(k)); }
    static Matrix I(size_t n) {
        Matrix mat(n);
        for (int i = 0; i < n; ++i) mat[i][i] = 1;
        return (mat);
    }
    Matrix& operator+=(const Matrix &B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                (*this)[i][j] += B[i][j];
        return (*this);
    }
    Matrix& operator-=(const Matrix &B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                (*this)[i][j] -= B[i][j];
        return (*this);
    }
    Matrix& operator*=(const Matrix &B) {
        size_t n = height(), m = B.width(), p = width();
        assert(p == B.height());
        vector< vector< T > > C(n, vector< T >(m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int k = 0; k < p; k++)
                    C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
        A.swap(C);
        return (*this);
    }
    Matrix& operator^=(long long k) {
        Matrix B = Matrix::I(height());
        while (k > 0) {
            if (k & 1) B *= *this;
            *this *= *this;
            k >>= 1LL;
        }
        A.swap(B.A);
        return *this;
    }
    Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }
    Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }
    Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }
    Matrix operator^(const long long k) const { return (Matrix(*this) ^= k); }
    friend ostream &operator<<(ostream &os, Matrix &p) {
        size_t n = p.height(), m = p.width();
        for (int i = 0; i < n; i++) {
            os << '[';
            for (int j = 0; j < m; j++) {
                os << p[i][j] << (j + 1 == m ? "]\n" : ',');
            }
        }
        return os;
    }
    T determinant() {
        Matrix B(*this);
        assert(width() == height());
        T ret = 1;
        for (int i = 0; i < width(); i++) {
            int idx = -1;
            for (int j = i; j < width(); j++) if (B[j][i] != 0) idx = j;
            if (idx == -1) return (0);
            if (i != idx) { ret *= -1; swap(B[i], B[idx]); }
            ret *= B[i][i];
            T vv = B[i][i];
            for (int j = 0; j < width(); j++) B[i][j] /= vv;
            for (int j = i + 1; j < width(); j++) {
                T a = B[j][i];
                for (int k = 0; k < width(); k++) B[j][k] -= B[i][k] * a;
            }
        }
        return ret;
    }
};

/*
・行列演算
[使用例]
Matrix<int> mat(n,m);   // n行m列の行列を定義
mat[i][j];              // i行j列目の要素を取得
mat.determinant();      // matの行列式を計算
mat ^= k;               // matのk乗を計算
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

