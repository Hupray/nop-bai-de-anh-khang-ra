#include<bits/stdc++.h>
#define HuphesRay main
#define ull unsigned long long
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define bit(mask,i) ((mask>>i)&1)
using namespace std;
const ll maxn = 1e6+5 , mod = 1e9+7 , inf = LLONG_MAX;
/*
/////// iam real noob coder ;-; //////////
          _________
        //         \\
      //            \\
    //               \\
    \\      NAH,     //
     \\     I'D     //
      \\    WIN.   //
       \\         //
        ====  ====
            \/
       _(UwU)_
         L L

https://i.kym-cdn.com/entries/icons/original/000/047/210/nah_id_win.jpg
*/

int t;
ll fact[3107] , invfact[3107];

ll power(ll x , ll n , ll mod) {
    ll ans = 1;
    while(n) {
        if(n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}

void precompute(int n) {
    n--;
    fact[0] = 1;
    for(int i = 1 ; i <= n ; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    invfact[n] = power(fact[n] , mod - 2 , mod);
    for(int i = n - 1 ; i >= 0 ; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % mod;
    }
}

ll comb(int n , int k) {
    if(k > n || k < 0 || n < 0) return 0;
    return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}

void sub3(int n , int m , int x) {
    x++;
    int sz = n + m - 2;
    ll ans = comb(sz , m - 1);
    ll bu = 0;
    for(int i = 1 ; i <= m ; i++) {
        ll bu = 0;
        if(n - 1 >= x * i) bu = comb(m , i) * comb(sz - i * x , m - 1) % mod;
        else break;
        ans = (ans + (i & 1 ? -bu : bu) + mod) % mod;
    }
    cout << ans;
}

void sub1(int n , int m , int x) {
    sub3(n , m , x);
}

void sub2(int n , int m , int x) {
    sub3(n , m , x);
}

void sol() {
    int n , m , x;
    cin >> n >> m >> x;
    //n = m = 1e3;
    //x = 1;
    /*
    if(n <= 5 && m <= 5) {
        sub1(n , m , x);
        return;
    }
    if(n <= 1e3 && m <= 1e3 && t == 1) {
        sub2(n , m , x);
        return;
    }
    */
    sub3(n , m , x);
}

int HuphesRay()
{
    fast;
    precompute(3107);
    cin >> t;
    while(t--) {
        sol();
        cout << '\n';
    }
    return 0;
}
/*
        /\_____/\
       /  o   o  \
      ( ==  ^  == )
       )         (
      /           \     Meow~~
     /             \
    (__(__)___(__)__)

        cre who?
        cre namdimine a.k.a hupray !
    https://oj.vnoi.info/user/PDNAM
        [Huphes Ray]
    ===================
// I really want to become a pro coder UwU//
*/