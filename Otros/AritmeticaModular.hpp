
#define ll long long
#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

// a*b%m;
// O(logN)
ll mulmod(ll a, ll b, ll m) {
    ll ret = 0;
    while (b) {
        if (b & 1) ret = (ret + a) % m; 
        a = (a << 1) % m; 
        b >>= 1;
    }
    return ret;
}

// x^n mod m
// O(logN)
ll fastPow(ll x, ll n, ll m) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = mulmod(ret,x, m); 
        // Recordar que solo lo tenemos que usar si
        // MOD>2^32, sino usar ret=ret*x%m;, 
        // ya que es tiempo constante
        x = mulmod(x,x, m);
        n >>= 1;
    }
    return ret;
}

// Greatest Common Divisor
// O(logN)
ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}


bool isPrime(ll n) {
    if (n<2) return false; 
    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        s++;
        d >>= 1;
    }
    int a[9] = {2,3,5,7,11,13,17,19,23 };
    FOR(i, 0, 9) if (a[i] == n) return true;
    FOR(i, 0, 9) {
        ll fp = fastPow(a[i], d, n);
        bool inv = fp != 1;
        FOR(j, 0, s) {
            if (fp == n - 1) inv = false;
            fp = mulmod(fp, fp, n);
        }
        if (inv) return false;
    }
    return true;
}

// void pollardRho(ll n) {
//     if (n == 1) return;
//     if (isPrime(n)) {
//         factorsPollardRho.pb(n);
//         return;
//     }
//     ll d = n, x, y;
//     while (d == n) {
//         d = 1;
//         x = y = 2;
//         A = 2 + rand() % (n - 2);
//         B = 2 + rand() % (n - 2);
//         while (d == 1) {
//             x = pseudoRandom(x, n);
//             y = pseudoRandom(pseudoRandom(y, n), n);
//             d = gcd(abs(x - y), n);
//         }
//     }
//     pollardRho(n / d);
//     pollardRho(d);
// }