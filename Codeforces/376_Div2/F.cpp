#include <fstream>
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define eps 1e-10
#define LL_INF 0x3fffffffffffffff
#define INF 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define pper(i,n,m) for(int i = n;i >= m; i--)
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int maxn = 200005;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}

ll n;
ll cnt[maxn],sum[maxn];

ll min(ll x,ll y)
{
    if(x<y)return x;
    else return y;
}

void solve()
{
    scanf("%lld",&n);
    repp(i,1,n)
    {
        ll x;
        scanf("%lld",&x);
        ++cnt[x];
    }
    repp(i,1,200000)
    {
        sum[i]=sum[i-1]+cnt[i];
    }

    ll ans = 0;
    repp(i,1,200000)
    {
        if(cnt[i])
        {
            ll res=0;
            for(ll j=i;j<=200000;j+=i)
            {
                res+=j*(sum[min(200000,j+i-1)]-sum[j-1]);
            }
            ans=max(ans,res);
        }
    }
    printf("%lld",ans);
}

int main()
{
    solve();
    return 0;
}