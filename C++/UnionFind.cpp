/*
・UnionFind木
  > O(α(n))
[使用例]
UnionFind uf(n);    // 頂点数nのUF木を宣言
uf.unite(a,b);      // 点a,b([0,n))が同じ集合に属する (すでに同じだったらfalseを返す)
bool isSameGroup = uf.same(a,b);  // 点a,bが同じ集合に属するか確認
cout << uf.find(a) << endl;       // 点aが属する集合を求める
cout << uf.size(a) << endl;       // 点aが属する集合の要素の数を求める
*/

struct UnionFind {
  vector<int> parent;
  int __size;
  UnionFind(int size_) : parent(size_, -1), __size(size_) {}
  bool unite(int x,int y) {
    if ((x=find(x)) != (y=find(y))) {
      if (parent[y] < parent[x]) swap(x,y);
      parent[x] += parent[y];
      parent[y] = x;
      __size--;
      return true;
    }
    return false;
  }
  bool same(int x,int y){return find(x)==find(y);}
  int find(int x){return parent[x] < 0 ? x : parent[x] = find(parent[x]);}
  int size(int x){return -parent[find(x)];}
  int size(){return __size;}
};

/*
・重み付きUnionFind木
  > O(α(n))
[使用例]
UnionFind_Weight uf(n);      // 頂点数nの重み付きUF木を宣言
uf.unite(a,b,w);              // 点a,b([0,n))が同じ集合に属し, それらの間の重みがwである (すでに同じだったらfalseを返す)
bool isSameGroup = uf.same(a,b);    // 点a,bが同じ集合に属するか確認
cout << uf.find(a) << endl;         // 点aが属する集合を求める
cout << uf.diff(a,b) << endl;       // 点a,bの間の重みを求める
*/

template<typename T> struct UnionFind_Weight {
  vector<int> parent;
  vector<int> rank;
  vector<T> diff_weight;
  UnionFind_Weight(int n = 1, T SUM_UNITY = 0) { init(n, SUM_UNITY); }
  void init(int n = 1, T SUM_UNITY = 0) {
    parent.resize(n); rank.resize(n); diff_weight.resize(n);
    for (int i = 0; i < n; ++i) parent[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
  }
  int find(int x) {
    if (parent[x] == x) return x;
    int ret = find(parent[x]);
    diff_weight[x] += diff_weight[parent[x]];
    return parent[x] = ret;
  }
  bool unite(int x, int y, T w) {
    w += weight(x); w -= weight(y);
    x = find(x); y = find(y);
    if (x == y) return false;
    if (rank[x] < rank[y]) swap(x, y), w = -w;
    if (rank[x] == rank[y]) ++rank[x];
    parent[y] = x;
    diff_weight[y] = w;
    return true;
  }
  T weight(int x) { find(x); return diff_weight[x]; }
  T diff(int x, int y) { return weight(y) - weight(x); }
  bool same(int x, int y) { return find(x) == find(y); }
};
