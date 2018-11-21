/*
・1次元累積和
  >     build O(n)
  > add,query O(1)
[使用例]
CumulativeSum<int> acc(n);      // 要素数nの累積和用の配列
acc.add(k,x);     // 要素kに値xを加える
acc.build();      // 累積和を取る
cout << acc.query(k) << endl;   // 区間[0,k]の和
*/

template<class T> struct CumulativeSum {
  vector<T> data;
  CumulativeSum(int sz) : data(sz, 0) {};
  void add(int k, int x) {
    data[k] += x;
  }
  void build() {
    for(int i = 1; i < data.size(); i++) {
      data[i] += data[i - 1];
    }
  }
  T query(int k)
  {
    if(k < 0) return (0);
    return (data[min(k, (int) data.size() - 1)]);
  }
};

/*
・2次元累積和
  >     build O(WH)
  > add,query O(1)
[使用例]
CumulativeSum2D<int> acc(M,N);  // acc[W+1][H+1]
acc.add(L,R,x);     // 要素(L,R)に値xを加える
acc.build();        // 累積和を取る
cout << acc.query(a,b,c,d) << endl;   // [a,b]から(c,d)までの和
*/

template<class T> struct CumulativeSum2D {
  vector<vector<T>> data;
  CumulativeSum2D(int W, int H) : data(W+1,vi(H+1,0)) {}
  void add(int x, int y, int z) {
    ++x, ++y;
    if (x >= data.size() || y >= data[0].size()) return;
    data[x][y] += z;
  }
  void build() {
    for(int i = 1; i < data.size(); ++i) {
      for(int j = 1; j < data[i].size(); ++j) {
        data[i][j] += data[i][j-1] + data[i-1][j] - data[i-1][j-1];
      }
    }
  }
  T query(int sx, int sy, int gx, int gy) {
    return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
  }
};
