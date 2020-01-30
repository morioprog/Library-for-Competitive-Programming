template<typename T = long long> struct CumulativeSum2D {
    vector< vector< T > > data;
    CumulativeSum2D(int H, int W) : data(H + 1, vector<T>(W + 1, 0)) {}
    void add(int x, int y, int z) {
        ++x, ++y;
        if (x >= data.size() || y >= data[0].size()) return;
        data[x][y] += z;
    }
    void build() {
        for(int i = 1; i < data.size(); ++i) {
            for(int j = 1; j < data[i].size(); ++j) {
                data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
            }
        }
    }
    T query(int sx, int sy, int gx, int gy) {
        return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
    }
};

/*
・2次元累積和
    >     build O(H * W)
    > add,query O(1)
[使用例]
CumulativeSum2D<int> acc(H, W);     // acc[H + 1][W + 1]
acc.add(L, R, x);                   // 要素(L, R)に値xを加える
acc.build();                        // 累積和を取る
acc.query(a, b, c, d);              // [a, b]から(c, d)までの和
*/
