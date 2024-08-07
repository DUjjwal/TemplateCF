// +++++++++++++++++Combinatorics+++++++++++++++++
const int mod=1e9+7;

vector <int> fac;
vector <int> ifac;

int power(int a,int b,int m)
{
    if(b==0)return 1;
    int t=power(a,b/2,m);
    if(b&1)
    return ((t*t)%m*a)%m;
    else
    return (t*t)%m;
}
void init(int len)
{
    fac.resize(len);
    ifac.resize(len);
    int f=1;
    fac[0]=1;
    ifac[0]=power(1,mod-2,mod);
    for(int i=1;i<=len;i++) {
        f=(f%mod*i%mod)%mod;
        fac[i]=f;
        ifac[i]=power(f,mod-2,mod);
    }
}
int ncr(int n,int r)
{
    int a=fac[n],b=ifac[n-r],c=ifac[r];
    int ans=((a*b)%mod * c%mod)%mod;
    return ans;
}
// +++++++++++++++++Combinatorics2+++++++++++++++++
int ncr(int n,int r)
{
    int num=1;
    for(int i=0;i<r;i++)
        num=(num%mod*(n-i)%mod)%mod;
    int den=1;
    for(int i=1;i<=r;i++)
        den=(den%mod*i%mod)%mod;
    return mod_div(num,den,mod);
}
// +++++++++++++++++Modular Arithmetic+++++++++++++++++
#define ll long long
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
