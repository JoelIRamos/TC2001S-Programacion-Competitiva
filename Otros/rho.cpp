#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define MOD 1000000007
#define maxN 1000

// a*b%m;
// O(logN)
ll mulmod(ll a, ll b, ll m) {
	ll ret = 0;
	while (b) {
		if (b & 1) 
			ret = (ret + a) % m; // Problema interesante: supongamos que ret+a puede excederse de 2^64 bits, como hacerle para no tener overflow??
		a = (a << 1) % m; 
		b >>= 1;
	}
	return ret;
}

// x^n mod m (tambien se usa la notacion x**n mod m)
// O(logN)
ll fastPow(ll x, ll n, ll m) {
	ll ret = 1;
	while (n) {
		if (n & 1) ret = mulmod(ret,x, m); // Recordar que solo lo tenemos que usar si MOD>2^32, sino usar ret=ret*x%m;, ya que es tiempo constante
		x = mulmod(x,x, m);
		n >>= 1;
	}
	return ret;
}

// Miller-Rabin primality test
// Over all Time Complexity is 9*(logN)**2, it can be said it's (logN)**3 because 9 is a 'big' constant
bool isPrime(ll n) {
	if (n<2) return false; //There shouldn't be any negative numbers here, though
	ll d = n - 1;
	int s = 0;
	while (d % 2 == 0) {
		s++;
		d >>= 1;
	}
	// It's garanteed that these values will work for any number smaller than 3*10**18 (3 and 18 zeros)
	int a[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
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

// p[i]==true if i is prime, otherwise false
bool p[maxN];


// Dos constantes pseudo aleatorias, ayudan a generar otros numeros pseudoaleatorios
ll A, B;

// Guarda los factores de un numero obtenidos mediante pollard rho
vector<ll> factorsPollardRho;


ll gcd(ll a, ll b) {
	if (b) return gcd(b, a%b);
	return a;
}

ll pseudoRandom(ll x, ll n) {
	return (mulmod(x, (x + A), n) + B) % n;
}

// Una funcion que se basa en el concepto de la paradoja del cumpleaÒos y otros conceptos para factorizar un numeros (es no deterministico, pero su complejidad es aproximadamente O(N^1/4))
void pollardRho(ll n) {
	if (n == 1) return;
	if (isPrime(n)) {
		factorsPollardRho.pb(n);
		return;
	}
	ll d = n, x, y;
	while (d == n) {
		d = 1;
		x = y = 2;
		A = 2 + rand() % (n - 2);
		B = 2 + rand() % (n - 2);

		while (d == 1) {
			x = pseudoRandom(x, n);
			y = pseudoRandom(pseudoRandom(y, n), n);
			d = gcd(abs(x - y), n);
		}
	}

	//if (n / d != d) ligera optimizacion, descomentar si solo nos interesan los factores primos, no cuantas veces aparecen
		pollardRho(n / d);
	pollardRho(d);
}

int main(){
	ll a, b;
	cin >> a;
	pollardRho(a);
	for (int i=0; i<factorsPollardRho.size(); i++){
		cout << factorsPollardRho[i] << " ";
	}
	cout << endl;
}