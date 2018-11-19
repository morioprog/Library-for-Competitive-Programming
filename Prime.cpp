/*
・素数判定
  > O(√n)
[使用例] cout << YES(isPrime(998244353)) << endl;
*/
bool isPrime(ll n) {
  if (n < 2) return false;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

/*
・エラトステネスの篩
  > O(nloglogn)
[使用例] vb prime = Eratosthenes(100000);
[備考] nが10^6以下のときに使うべき
*/
inline vb Eratosthenes(const int n) {
  vb r(n+1,true);
  for(int i=2;i*i<=n;++i){
    if(r[i]){
      for(int j=i*2;j<=n;j+=i)r[j]=false;
    }
  }
  if(r.size()>2){r[0]=0;r[1]=0;}
  else if(r.size()>1){r[0]=0;}
  return r;
}
