/* include */
#include <bits/stdc++.h>
/*
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <random>
#include <cassert>
#include <limits>
*/
/* Multiprecision */
/*
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using Bint = boost::multiprecision::cpp_int;
using Bfloat32 = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<32> >;
using Bfloat1024 = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1024> >;
//*/
using namespace std;
//#define int long long
/* typedef */
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
typedef vector<bool> vb;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int> > vvi;
/* const */
const int INF = 1e9;
const int MOD = 1e9 + 7;
const double PI  = acos(-1.0);
const double EPS = 1e-9;
const ll INFF = 1e18;
const ll INTMAX = (0x7FFFFFFFL);
const ll LLMAX = (0x7FFFFFFFFFFFFFFFL);
int dx[9] = { 1, 0, -1,  0,  1, -1, -1, 1, 0 };
int dy[9] = { 0, 1,  0, -1, -1, -1,  1, 1, 0 };
/* input */
#define S(s) cin >> (s);
#define SS(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T& t){cin >> t;}
template<typename First, typename...Rest> void MACRO_VAR_Scan(First& first, Rest&...rest){cin >> first;MACRO_VAR_Scan(rest...);}
#define SV(type,c,n) vector<type> c(n);for(auto& i:c)cin >> i;
#define SVV(type,c,n,m) vector<vector<type>> c(n,vector<type>(m));for(auto& r:c)for(auto& i:r)cin >> i;
/* output */
template<class T>ostream &operator<<(ostream &o,const vector<T>&j){o<<"{";for(int i=0;i<(int)j.size();++i)o<<(i>0?", ":"")<<j[i];o<<"}";return o;}
template<class T,class U>ostream &operator<<(ostream &o,const pair<T,U>&j){o<<"{"<<j.first<<", "<<j.second<<"}";return o;}
template<class T,class U>ostream &operator<<(ostream &o,const map<T,U>&j){o<<"{";for(auto t=j.begin();t!=j.end();++t)o<<(t!=j.begin()?", ":"")<<*t;o<<"}";return o;}
template<class T>ostream &operator<<(ostream &o,const set<T>&j){o<<"{";for(auto t=j.begin();t!=j.end();++t)o<<(t!=j.begin()?", ":"")<<*t;o<<"}";return o;}
void print(void){cout << endl;}
template<class Head> void print(Head&& head){cout << head;print();}
template<class Head,class... Tail> void print(Head&& head,Tail&&... tail){cout<<head<<" ";print(forward<Tail>(tail)...);}
template<typename T> void PA(T &a){int ASIZE=sizeof(a)/sizeof(a[0]);for(int ii=0;ii<ASIZE;++ii){cout<<a[ii]<<" \n"[ii==ASIZE-1];}}
template<typename T> void PV(T &v){int VSIZE=v.size();for(int ii=0;ii<VSIZE;++ii){cout<<v[ii]<<" \n"[ii==VSIZE-1];}}
#define ER(x)  cerr << #x << " = " << (x) << endl;
#define ERV(v) {cerr << #v << " : ";for(const auto& xxx : v){cerr << xxx << " ";}cerr << "\n";}
#define YES(x) cout<<((x)?"YES":"NO")<<endl;
#define Yes(x) cout<<((x)?"Yes":"No")<<endl;
#define yes(x) cout<<((x)?"yes":"no")<<endl;
#define yES(x) cout<<((x)?"yES":"nO")<<endl;
#define Yay(x) cout<<((x)?"Yay!":":(")<<endl;
#define sankou(x,a,b) cout<<((x)?(a):(b))<<endl;
/* repetition */
#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define _RREP(i,n) RREPI(i,n,0)
#define RREPI(i,a,b) for(ll i=ll(a);i>=ll(b);--i)
#define RREP(...) _overload3(__VA_ARGS__,RREPI,_RREP,)(__VA_ARGS__)
#define EACH(e,v) for(auto& e : v)
#define PERM(v) sort((v).begin(),(v).end());for(bool c##p=1;c##p;c##p=next_permutation((v).begin(),(v).end()))
/* calculation */
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline ll lcm(ll a,ll b){return a*b/gcd(a,b);}
inline ll POW(ll a,ll b){ll c=1ll;do{if(b&1)c*=1ll*a;a*=1ll*a;}while(b>>=1);return c;}
inline ll bit(ll x){return (1ll << x);}
inline bool isPrime(int x){
  if(x<2) return false;
  if(x==2) return true;
  if(x%2==0) return false;
  for(int i=3;i<=sqrt(x)+1;i+=2) if(x%i==0) return false;
  return true;
}
inline vb Eratosthenes(const int n) {        // ~10^6: Eratosthenes
  vb r(n+1,true);                           // 10^7~: Simple
  for(int i=2;i*i<=n;++i){
    if(r[i]){
      for(int j=i*2;j<=n;j+=i)r[j]=false;
    }
  }
  if(r.size()>2){r[0]=0;r[1]=0;}
  else if(r.size()>1){r[0]=0;}
  return r;                                 // [0,n)
}
template<typename T> inline bool between(T x,T a,T b) {return ((a<=x)&&(x<b));}
template<class T> inline T sqr(T x){return x*x;}
template<typename A,typename B> inline bool chmax(A &a,const B &b){if(a<b){a=b;return 1;}return 0;}
template<typename A,typename B> inline bool chmin(A &a,const B &b){if(a>b){a=b;return 1;}return 0;}
#define tmax(x,y,z) max((x),max((y),(z)))
#define tmin(x,y,z) min((x),min((y),(z)))
inline ll digitsum(ll x){ll d;ll r=0;while(x){d=x%10;r+=d;x/=10;}return r;}
/* modulo */
#define ADD(a,b) a=(a+ll(b))%MOD
#define MUL(a,b) a=(a*ll(b))%MOD
ll MOP(ll x,ll n,ll m=MOD){ll r=1;while(n>0){if(n&1)(r*=x)%=m;(x*=x)%=m;n>>=1;}return r;}
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
/* conversion */
inline ll toInt(string s){ll v;istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout << x;return sout.str();}
template<typename T> inline void ntos(const T &n,string &s){stringstream stream; stream << n; stream >> s;}
template<typename T> inline void ston(const string &s,T &n){stringstream stream(s); stream >> n;}
/* container */
#define fst first
#define snd second
#define PB push_back
#define MP make_pair
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define SORT(v) sort((v).begin(),(v).end())
#define RSORT(v) sort((v).rbegin(),(v).rend())
#define EXIST(s,e) (find((s).begin(),(s).end(),(e))!=(s).end())
#define EXISTST(s,c) (((s).find(c))!=string::npos)
#define POSL(x,val) (lower_bound(x.begin(),x.end(),val)-x.begin())
#define POSU(x,val) (upper_bound(x.begin(),x.end(),val)-x.begin())
#define SZV(a) int((a).size())
#define SZA(a) sizeof(a)/sizeof(a[0])
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MEMINF(a) memset(a,0x3f,sizeof(a))
#define FILL(a,b) memset(a,b,sizeof(a))
#define UNIQUE(v) sort((v).begin(),(v).end());(v).erase(unique((v).begin(),(v).end()),(v).end())
bool SORT_PAIR_SECOND(const pii& a,const pii& b){return a.second<b.second;}
/* other */
#define scnaf scanf
#define sacnf scanf
#define sancf scanf
#define ln '\n'
#define y0 yqzectb
#define y1 ywxrvyn
#define j0 jqezcwr
#define j1 jkhouwd
/* UnionFind */
struct UnionFind {
    vector<int> parent;
    int __size;
    UnionFind(int size_) : parent(size_, -1), __size(size_) {}
    void unite(int x,int y) {
        if ((x=find(x)) != (y=find(y))) {
            if (parent[y] < parent[x]) swap(x,y);
            parent[x] += parent[y];
            parent[y] = x;
            __size--;
        }
    }
    bool same(int x,int y){return find(x)==find(y);}
    int find(int x){return parent[x] < 0 ? x : parent[x] = find(parent[x]);}
    int size(int x){return -parent[find(x)];}
    int size(){return __size;}
};
/* graph */
using Weight = int;         // !!!OVERFLOW!!!
using Flow = int;
struct Edge {
    int src, dst;
    Weight weight;
    Flow cap;
    Edge() : src(0), dst(0), weight(0) {}
    Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;
void add_edge(Graph &g,int a,int b,Weight w=1){g[a].emplace_back(a,b,w);g[b].emplace_back(b,a,w);}
void add_arc(Graph &g,int a,int b,Weight w=1){g[a].emplace_back(a,b,w);}
Matrix WarshallFloyd(const Graph &g) {
    auto const INF = std::numeric_limits<Weight>::max()/8;
    int n = g.size();
    Matrix d(n,Array(n,INF));
    REP(i,n) d[i][i] = 0;
    REP(i,n) for(auto &e : g[i]) d[e.src][e.dst]=min(d[e.src][e.dst],e.weight);
    REP(k,n) REP(i,n) REP(j,n) if(d[i][k]!=INF && d[k][j]!=INF) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    return d;
}
vector<Weight> Dijkstra(const Graph &g,int s) {
    const Weight INF = numeric_limits<Weight>::max()/8;
    using state = tuple<Weight,int>;
    priority_queue<state> q;
    vector<Weight> dist(g.size(),INF);
    dist[s] = 0;
    q.emplace(0,s);
    while (q.size()) {
        Weight d;
        int v;
        tie(d,v) = q.top(); q.pop();
        d *= -1;
        /* if(v == t) return d; */
        if (dist[v]<d) continue;
        for (auto &e : g[v]) {
            if (dist[e.dst] > dist[v] + e.weight) {
                dist[e.dst] = dist[v] + e.weight;
                q.emplace(-dist[e.dst], e.dst);
            }
        }
    }
    return dist;
}
/* abracadabra */
struct abracadabra{
    abracadabra(){
        cin.tie(0); ios::sync_with_stdio(0);
        cout << fixed << setprecision(20);
    };
} ABRACADABRA;

//---------------8<---------------8<---------------8<---------------8<---------------//

signed main() {



}
