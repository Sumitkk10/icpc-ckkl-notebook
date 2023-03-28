int n, k, a[N], l = 1, r, distinct, mp[N], sz = sqrt(N);
// number of distinct elements in a range.
struct st{
    int L, R, i;
};
bool cmp(st a, st b){
    if(a.L/sz == b.L/sz)
        return a.R < b.R;
    return a.L < b.L;
}
void cost(int i, int j){
    while(l > i){
        --l;
        if(!mp[a[l]]) ++distinct;
        mp[a[l]]++;
    }
    while(l < i){
        if(mp[a[l]] == 1) --distinct;
        mp[a[l]]--;
        ++l;
    }
    while(r > j){
        if(mp[a[r]] == 1) --distinct;
        mp[a[r]]--;
        --r;
    }
    while(r < j){
        ++r;
        if(!mp[a[r]]) ++distinct;
        mp[a[r]]++;
    }
}
// snippet from main:
st qq[q];
    for(int i = 0; i < q; ++i){
        cin >> qq[i].L >> qq[i].R;
        qq[i].i = i;
        qq[i].L, qq[i].R;
    }
    vector<int> ans(q);
    sort(qq, qq + q, cmp);
    for(int i = 0; i < q; ++i){
        cost(qq[i].L, qq[i].R);
        ans[qq[i].i] = distinct;
    }
