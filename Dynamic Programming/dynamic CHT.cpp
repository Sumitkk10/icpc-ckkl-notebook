/*
impl details : 
maintain a vector of CHT's
to find maximum, slopes should be in increasing order.
merge them toghther when same size 
*/
struct Line{
    int m, c;

    int val(int x){
        return m*x + c;
    }
};
vector<pair<vector<Line>, int> > hulls;
vector<Line> merge(vector<Line> a, vector<Line> b){
    // a and b is already sorted in increasing order of slopes
    vector<Line> ans;
    int i = 0, j = 0;
    while(i < a.size() and j < b.size()){
        if(a[i].m <= b[j].m){
            ans.pb(a[i]);
            ++i;
        }
        else{
            ans.pb(b[j]);
            ++j;
        }
    }
    while(i < a.size()){
        ans.pb(a[i]);
        ++i;
    }
    while(j < b.size()){
        ans.pb(b[j]);
        ++j;
    }
    return ans;
}
bool check(Line a, Line b, Line c) {
    // do a and c cover b?
    __int128 left = (b.c - a.c);
    left = left * (b.m - c.m);
    __int128 right = (c.c - b.c);
    right = right * (a.m - b.m);
    return left > right;
}
bool cmp(Line a, Line b){
    if(a.m == b.m)
        return a.c > b.c;
    return a.m < b.m;
}
vector<Line> CHT(vector<Line> cur){
    sort(cur.begin(), cur.end(), cmp);
    vector<Line> temp;
    temp.pb(cur[0]);
    for(int i = 1; i < cur.size(); ++i){
        if(cur[i].m == temp.back().m)
            continue;
        temp.pb(cur[i]);
    }
    cur = temp;
    vector<Line> hull;
    hull.pb(cur[0]); // first line will always be in the hull
    if(cur.size() == 1)
        return hull;
    hull.pb(cur[1]); // assuming this line is also in the hull
    for(int j = 2; j < cur.size(); ++j){
        while(hull.size() > 1){
            Line pre = hull.back(), par = hull[hull.size() - 2];
            if(check(par, pre, cur[j]))
                hull.pop_back();
            else
                break;
        }
        hull.pb(cur[j]);
    }
    return hull;
}
void addLine(Line a){
    vector<Line> cur;
    cur.pb(a);
    hulls.pb({cur, 1});
    // you should merge last two if both are same size
    while(hulls.size() > 1){
        vector<Line> cur = hulls[hulls.size() - 1].F, pre = hulls[hulls.size() - 2].F;
        if(hulls[hulls.size() - 1].S == hulls[hulls.size() - 2].S){
            // merge these two hulls into one
            vector<Line> ans;
            ans = CHT(merge(pre, cur));
            int x = hulls[hulls.size() - 1].S + hulls[hulls.size() - 2].S;
            hulls.pop_back();
            hulls.pop_back();
            hulls.push_back({ans, x});
        }
        else
            break;
    }
}
int get(int x){
    int res = LLONG_MIN;
    for(auto &k : hulls){
        int low = 0, high = (int) k.F.size() - 1;
        while(low < high){
            int mid = (low + high) / 2;
            int mid1 = mid + 1;
            if(k.F[mid].val(x) < k.F[mid1].val(x))
                low = mid1;
            else
                high = mid;
        }
        // cout << ans << "\n";
        res = max(res, k.F[low].val(x));
    }
    return res;
}
