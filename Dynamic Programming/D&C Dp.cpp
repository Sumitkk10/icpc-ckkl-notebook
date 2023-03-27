/*
we can use d&c dp optimization when we have a recurrence : 
dp[i] = min(dp[j] + C(j..i)) for all j < i
dp[i][j] = min(dp[k][j - 1] + C(k..i)) for all k < i
observe that opt[i] will be monotonic, opt[i] <= opt[i + 1]
then we can use d&c optimization. :)
*/
vector<ll> dp_b4(N), cur_dp(N);
int C(int x, int xx){
    if(xx < x) return LLONG_MAX;
    int ans = ((xx - x)*(pre_sum[xx] - pre_sum[x]));
    return ans;
}
void compute(int l, int r, int optl, int optr) {
    if (l > r)
        return;
    int mid = (l + r) >> 1;
    int best = LLONG_MAX, idx;
    for (int i = optl; i <= min(mid, optr); i++) {
        if(i == mid) continue;
        if(best > dp_b4[i] + C(i, mid)){
            best = dp_b4[i] + C(i, mid);
            idx = i;
        }
    }
    cur_dp[mid] = best;
    compute(l, mid - 1, optl, idx);
    compute(mid + 1, r, idx, optr);
}
// in main
for(int i = 1; i <= n; ++i)
    dp_b4[i] = C(0, i);
for(int j = 2; j <= k; ++j){
    compute(1, n, 0, n - 1);
    dp_b4 = cur_dp;
}
