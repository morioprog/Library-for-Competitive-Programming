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
*/
