/*
・BitMatrix
[備考] F_2上の行列操作
[注意] MAX_ROW, MAX_COLを問題ごとに変えること
[使用例]
BitMatrix mat(N, M);            // N行M列の行列を作成
gaussian_elimination(mat);      // matに対してガウスの消去法を適用
linear_equation(A, b, res);     // 連立方程式 A * res = b を解く
*/

const int MAX_ROW = 510;
const int MAX_COL = 510;
struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL>& operator[](int i) { return val[i]; }
};
ostream& operator<<(ostream& s, BitMatrix A) {
    s << endl; 
    for (int i = 0; i < A.H; ++i) {
        for (int j = 0; j < A.W; ++j) {
            s << A[i][j] << ", ";
        }
        s << endl;
    }
    return s;
}
inline BitMatrix operator*(BitMatrix A, BitMatrix B) {
    BitMatrix R(A.H, B.W), tB(B.W, B.H);
    for (int i = 0; i < tB.H; ++i) for (int j = 0; j < tB.W; ++j) tB[i][j] = B[j][i];
    for (int i = 0; i <  R.H; ++i) for (int j = 0; j <  R.W; ++j)  R[i][j] = ((A[i] & tB[j]).count() & 1);
    return R;
}
inline BitMatrix pow(BitMatrix A, uint_fast64_t n) {
    BitMatrix R(A.H, A.H);
    for (int i = 0; i < A.H; ++i) R[i][i] = 1;
    while (n > 0) {
        if (n & 1) R = R * A;
        A = A * A;
        n >>= 1;
    }
    return R;
}
int gaussian_elimination(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for (int col = 0; col < A.W; ++col) {
        if (is_extended and col == A.W - 1) break;
        int pivot = -1;
        for (int row = rank; row < A.H; ++row) {
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]);
        for (int row = 0; row < A.H; ++row) {
            if (row != rank and A[row][col]) A[row] ^= A[rank];
        }
        ++rank;
    }
    return rank;
}
int linear_equation(BitMatrix A, vector<int> b, vector<int> &res) {
    int m = A.H, n = A.W;
    BitMatrix M(m, n + 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = gaussian_elimination(M, true);
    for (int row = rank; row < m; ++row) if (M[row][n]) return -1;
    res.assign(n, 0);
    for (int i = 0; i < rank; ++i) res[i] = M[i][n];
    return rank;
}
