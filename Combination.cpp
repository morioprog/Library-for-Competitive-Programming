/*
・組み合わせ, 順列, 重複組み合わせ
  > 前計算 O(MAX_N + logMOD)
  > クエリ O(1)
[使用例]
COMinit();                   // MAX_Nまでの前計算
cout << nCr(n,r) << endl;    // nCr (0 <= (n,r) <= MAX_N)
cout << nPr(n,r) << endl;    // nPr ( ... )
cout << nHr(n,r) << endl;    // nHr ( ... )
*/

const int MAX_N = 2020202;
ll fac[MAX_N], finv[MAX_N], inv[MAX_N];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    REP(i,2,MAX_N) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll nCr(ll n, ll r) { if (r<0 || n<r) return 0; else return (fac[n]*((finv[n-r]*finv[r])%MOD))%MOD; }
ll nPr(ll n, ll r) { if (r<0 || n<r) return 0; else return (fac[n]*finv[n-r])%MOD; }
ll nHr(ll n, ll r) { if (n==0 && r==0) return 1; else return nCr(n+r-1,r); }

/*
・nが大きい(rが小さい)ときの組み合わせ
  > クエリ O(r)
[使用例] cout << comb(n,r) << endl;
*/

ll comb(ll n, int r) {
  if (r<0 || n<r) return 0;
  ll ret=1;
  REP(i,1,r+1) (ret*=n--)/=i;
  return ret;
}
