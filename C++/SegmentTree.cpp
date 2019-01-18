/*
・セグメント木
  >         build O(N)
  > query, update O(logN)
[備考] 結合律, 単位元を持つ二項演算を, 任意の区間に関してlogNで行うデータ構造
[使用例]
SegmentTree<int> seg_sum(N, [](int a, int b){ return a+b; }, 0 );       // 区間和
SegmentTree<int> seg_min(N, [](int a, int b){ return min(a,b); }, INF); // 区間min
seg_min.set(k,x);     // 要素kに値xを設定
seg_min.build();      // 上のセグメントに値を設定
seg_min.update(k,x);  // 要素kを値xに変更
seg_min.add(k,x);     // 要素kに値xを加算
seg_min.query(l,r);   // 区間[l,r)に対する二項演算の結果を返す
*/

template<typename T> struct SegmentTree {

  using F = function< T(T,T) >;

  vector< T > seg;

  int size;       // データの数以上の最小の2冪, 最下段のデータの個数
  const F func;
  const T M1;

  SegmentTree(int n, const F f, const T &M) : func(f), M1(M) {
    size = 1; while (size < n) size *= 2;
    seg.resize(2 * size - 1, M1);
  }

  void set(int k, T x) {
    seg[k + size - 1] = x;
  }

  void build() {
    for (int i = size - 2; i >= 0; --i) {
      // iの子は, (2*i+1, 2*i+2)
      seg[i] = func(seg[2*i+1], seg[2*i+2]);
    }
  }

  void update(int k, T x) {
    // kをseg内の添字に対応させる <- (size - 1)を足す
    k += size - 1;
    seg[k] = x;
    while (k > 0) {
      k = (k - 1) / 2;
      seg[k] = func(seg[2*k+1], seg[2*k+2]);
    }
  }

  void add(int k, T x) {
    // kをseg内の添字に対応させる <- (size - 1)を足す
    k += size - 1;
    seg[k] += x;
    while (k > 0) {
      k = (k - 1) / 2;
      seg[k] = func(seg[2*k+1], seg[2*k+2]);
    }
  }

  T query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = size;
    if (r <= a || l >= b) return M1;
    if (l >= a && r <= b) return seg[k];
    T f_l = query(a, b, 2*k+1, l, (l+r)/2);
    T f_r = query(a, b, 2*k+2, (l+r)/2, r);
    return func(f_l, f_r);
  }

  void debug() {
    for (int i = 0; i < 2 * size - 1; ++i) {
      cerr << seg[i] << " \n"[i==2*size-2];
    }
  }

};

/*
・遅延評価セグメント木
	> query, update O(logN)
[引数]
LazySegmentTree<Monoid, OperatorMonoid> seg(sz, f, g, h, d1, d0, v, p);
> sz : 要素数
>  f : 要素と要素をマージする関数
>  g : 要素に作用素を作用させる関数
>  h : 作用素と作用素をマージする関数
> d1 : 要素のモノイド
> d0 : 作用素のモノイド
>  v : 初期化用の配列
>  p : 区間に対する操作が要素数に比例して変化する場合 ( p(a, b) = g(a, a, ..., a) [aはb個] )
[備考]
以下の3つの条件を満たすときに使える
1. g(f(a, b), c) = f(g(a, c), g(b, c))
( 1'. g(f(a, b), p(c, d)) = f(g(a, p(c, d / 2)), g(b, p(c, d / 2))) )
2. g(g(a, b), c) = g(a, h(b, c))
3. g(a, d0) = a
[典型例]
> 区間加算 -> 区間和
LazySegmentTree<ll> seg(N, plus<ll>(), plus<ll>(), plus<ll>(), 0, 0, vl(N,0), multiplies<ll>());
> 区間加算 -> 区間最小
LazySegmentTree<ll> seg(N, [](ll a,ll b){return min(a,b);}, plus<ll>(), plus<ll>(), INFF, 0);
> 区間更新 -> 区間和
LazySegmentTree<ll> seg(N, plus<ll>(), [](ll a,ll b){return b;}, [](ll a,ll b){return b;}, 0, INFF, vl(N,0), multiplies<ll>());
> 区間更新 -> 区間最小
LazySegmentTree<ll> seg(N, [](ll a,ll b){return min(a,b);}, [](ll a,ll b){return b;}, [](ll a,ll b){return b;}, INFF, INFF);
[使用例]
seg.update(l, r, x);			// 半開区間[l, r)に作用素xを作用
seg.query(l, r);					// 半開区間[l, r)に対する演算の結果
seg[k];										// k番目の要素を取得
*/

template <typename Monoid, typename OperatorMonoid = Monoid> struct LazySegmentTree {

  typedef function< Monoid(Monoid, Monoid) > F;
  typedef function< Monoid(Monoid, OperatorMonoid) > G;
  typedef function< OperatorMonoid(OperatorMonoid, OperatorMonoid) > H;
  typedef function< OperatorMonoid(OperatorMonoid, int) > P;

  int sz;
  F f;
  G g;
  H h;
  P p;
  Monoid d1;
  OperatorMonoid d0;
  vector< Monoid > dat;
  vector< OperatorMonoid > laz;

  LazySegmentTree(int n, F f, G g, H h, Monoid d1, OperatorMonoid d0,
              vector< Monoid > v = vector< Monoid >(), P p = [] (OperatorMonoid a, int b) { return a; })
              : f(f), g(g), h(h), d1(d1), d0(d0), p(p) {
    sz = 1; while (sz < n) sz <<= 1;
    dat.assign(2 * sz - 1, d1);
    laz.assign(2 * sz - 1, d0);
    if (n == (int)v.size()) build(n, v);
  }

  void build(int n, vector<Monoid> &v) {
    for (int i = 0; i < n; i++)
      dat[i + sz - 1] = v[i];
    for (int i = sz - 2; i >= 0; i--)
      dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
  }

  inline void eval(int len, int k) {
    if (laz[k] == d0) return;
    if (k * 2 + 1 < sz * 2 - 1) {
      laz[k * 2 + 1] = h(laz[k * 2 + 1], laz[k]);
      laz[k * 2 + 2] = h(laz[k * 2 + 2], laz[k]);
    }
    dat[k] = g(dat[k], p(laz[k], len));
    laz[k] = d0;
  }

  Monoid update(int a, int b, OperatorMonoid x, int k, int l, int r) {
    eval(r - l, k);
    if(r <= a || b <= l) return dat[k];
    if(a <= l && r <= b) {
      laz[k] = h(laz[k], x);
      return g(dat[k], p(laz[k], r - l));
    }
    return dat[k] = f(update(a, b, x, k * 2 + 1, l, (l + r) / 2),
		    update(a, b, x, k * 2 + 2, (l + r) / 2, r));
  }

  Monoid update(int a, int b, OperatorMonoid x) {
    return update(a, b, x, 0, 0, sz);
  }

  Monoid query(int a, int b, int k, int l, int r) {
    eval(r - l, k);
    if (r <= a || b <= l) return d1;
    if (a <= l && r <= b) return dat[k];
    Monoid vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    Monoid vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return f(vl, vr);
  }

  Monoid query(int a, int b) {
    return query(a, b, 0, 0, sz);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }

};
