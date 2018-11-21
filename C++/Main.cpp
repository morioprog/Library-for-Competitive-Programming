#include <bits/stdc++.h>
using namespace std;
typedef long long ll;       typedef long double ld;  typedef pair<int,int> pii; typedef pair<ll,ll> pll;  typedef vector<int> vi;   typedef vector<ll> vl;
typedef vector<string> vst; typedef vector<bool> vb; typedef vector<ld> vld;    typedef vector<pii> vpii; typedef vector<pll> vpll; typedef vector<vector<int> > vvi;
const int INF = (0x7FFFFFFFL); const ll INFF = (0x7FFFFFFFFFFFFFFFL);
const int MOD = 1e9 + 7;       const int MODD = 998244353;
const double PI  = acos(-1.0); const double EPS = 1e-9;
int dx[9] = { 1, 0, -1,  0,  1, -1, -1, 1, 0 };
int dy[9] = { 0, 1,  0, -1, -1, -1,  1, 1, 0 };
#define ln '\n'
#define scnaf scanf
#define sacnf scanf
#define sancf scanf
#define SS(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T& t){cin >> t;}template<typename First, typename...Rest> void MACRO_VAR_Scan(First& first, Rest&...rest){cin >> first;MACRO_VAR_Scan(rest...);}
#define SV(type,c,n) vector<type> c(n);for(auto& i:c)cin >> i;
#define SVV(type,c,n,m) vector<vector<type>> c(n,vector<type>(m));for(auto& r:c)for(auto& i:r)cin >> i;
template<class T>ostream &operator<<(ostream &o,const vector<T>&j){o<<"{";for(int i=0;i<(int)j.size();++i)o<<(i>0?", ":"")<<j[i];o<<"}";return o;}
template<class T,class U>ostream &operator<<(ostream &o,const pair<T,U>&j){o<<"{"<<j.first<<", "<<j.second<<"}";return o;}
template<class T,class U>ostream &operator<<(ostream &o,const map<T,U>&j){o<<"{";for(auto t=j.begin();t!=j.end();++t)o<<(t!=j.begin()?", ":"")<<*t;o<<"}";return o;}
template<class T>ostream &operator<<(ostream &o,const set<T>&j){o<<"{";for(auto t=j.begin();t!=j.end();++t)o<<(t!=j.begin()?", ":"")<<*t;o<<"}";return o;}
inline void print(void){cout << endl;}
template<class Head> void print(Head&& head){cout << head;print();} template<class Head,class... Tail> void print(Head&& head,Tail&&... tail){cout<<head<<" ";print(forward<Tail>(tail)...);}
template<typename T> void PA(T &a){int ASIZE=sizeof(a)/sizeof(a[0]);for(int ii=0;ii<ASIZE;++ii){cout<<a[ii]<<" \n"[ii==ASIZE-1];}}
template<typename T> void PV(T &v){int VSIZE=v.size();for(int ii=0;ii<VSIZE;++ii){cout<<v[ii]<<" \n"[ii==VSIZE-1];}}
#define ER(x)  cerr << #x << " = " << (x) << endl;
#define ERV(v) {cerr << #v << " : ";for(const auto& xxx : v){cerr << xxx << " ";}cerr << "\n";}
inline void YES(bool x){cout<<((x)?"YES":"NO")<<endl;} inline void Yes(bool x){cout<<((x)?"Yes":"No")<<endl;}  inline void yes(bool x){cout<<((x)?"yes":"no")<<endl;}
inline void yES(bool x){cout<<((x)?"yES":"nO")<<endl;} inline void Yay(bool x){cout<<((x)?"Yay!":":(")<<endl;}
template<typename A,typename B> void sankou(bool x,A a,B b){cout<<((x)?(a):(b))<<endl;}
#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define _RREP(i,n) RREPI(i,n,0)
#define RREPI(i,a,b) for(ll i=ll(a);i>=ll(b);--i)
#define RREP(...) _overload3(__VA_ARGS__,RREPI,_RREP,)(__VA_ARGS__)
#define EACH(e,v) for(auto& e : v)
#define PERM(v) sort((v).begin(),(v).end());for(bool c##p=1;c##p;c##p=next_permutation((v).begin(),(v).end()))
#define ADD(a,b) a=(a+ll(b))%MOD
#define MUL(a,b) a=(a*ll(b))%MOD
inline ll MOP(ll x,ll n,ll m=MOD){ll r=1;while(n>0){if(n&1)(r*=x)%=m;(x*=x)%=m;n>>=1;}return r;}
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}inline ll lcm(ll a,ll b){return a*b/gcd(a,b);}inline ll POW(ll a,ll b){ll c=1ll;do{if(b&1)c*=1ll*a;a*=1ll*a;}while(b>>=1);return c;}
template<typename T> inline bool between(T x,T a,T b) {return ((a<=x)&&(x<b));}template<class T> inline T sqr(T x){return x*x;}
template<typename A,typename B> inline bool chmax(A &a,const B &b){if(a<b){a=b;return 1;}return 0;}
template<typename A,typename B> inline bool chmin(A &a,const B &b){if(a>b){a=b;return 1;}return 0;}
#define tmax(x,y,z) max((x),max((y),(z)))
#define tmin(x,y,z) min((x),min((y),(z)))
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
struct abracadabra{
    abracadabra(){
        cin.tie(0); ios::sync_with_stdio(0);
        cout << fixed << setprecision(20);
    };
} ABRACADABRA;
//#define int long long

//---------------8<---------------8<---------------8<---------------8<---------------//

signed main() {



}
