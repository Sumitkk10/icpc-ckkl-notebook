int power(int x, int y){
    x %= MOD;
    int ans = 1;
    while(y){
        if(y & 1)
            ans = (ans * x) % MOD;
        y >>= 1LL;
        x = (x * x) % MOD;
    }
    return ans;
}
int add(int a, int b){
    return((a % MOD + b % MOD) % MOD);
}
int sub(int a, int b){
    return((a % MOD - b % MOD + MOD) % MOD);
}
int mul(int a, int b){
    return(((a % MOD) * (b % MOD)) % MOD);
}
int divi(int a, int b){
    return(mul(a, power(b, MOD - 2)) % MOD);
}
