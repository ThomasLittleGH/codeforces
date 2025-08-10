ll fact[MAXN], inv_fact[MAXN];
 
ll power(ll x, ll y){ // x^y;
    ll res = 1;
 
    while (y){ // Mientres me queden valores de i.
               // La idea es aumentar la base x al cuadrado hasta que pueda aplicar los cambios en res.
        if (y & 1) res = (res * x) % MOD; 
        x = (x * x) % MOD;
        y >>= 1;
    }
 
    return res;
}
 
void precompute(){
    fact[0] = 1;
 
    repx(i, 1, MAXN) fact[i] = (fact[i - 1] * i) % MOD;
    inv_fact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2); 
    for (int i = MAXN - 2; i > -1; i--) inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
}
 
inline ll nCr(int n, int x){
    if (x < 0 || n < x) return 0;
    return ((fact[n] * inv_fact[x]) % MOD * inv_fact[n - x]) % MOD;
}
