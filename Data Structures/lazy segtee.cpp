void build(int vertex, int l, int r){
    lazy[vertex] = 0;
    if(l > r)
        return;
    if(l == r){
        val[vertex] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * vertex, l, mid);
    build(2 * vertex + 1, mid + 1, r);
    val[vertex] = min(val[2 * vertex], val[2 * vertex + 1]);
}
void update(int vertex, int l, int r, int tl, int tr, int value){
    if(lazy[vertex] != 0){
        val[vertex] += lazy[vertex];
        lazy[2 * vertex] += lazy[vertex];
        lazy[2 * vertex + 1] += lazy[vertex];
        lazy[vertex] = 0;
    }
    if(l > tr or r < tl)
        return;
    if(l >= tl and r <= tr){
        val[vertex] += value;
        lazy[2 * vertex] += value;
        lazy[2 * vertex + 1] += value;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * vertex, l, mid, tl, tr, value);
    update(2 * vertex + 1, mid + 1, r, tl, tr, value);
    val[vertex] = min(val[2 * vertex], val[2 * vertex + 1]);
}
int get(int vertex, int l, int r, int tl, int tr){
    if(lazy[vertex] != 0){
        val[vertex] += lazy[vertex];
        lazy[2 * vertex] += lazy[vertex];
        lazy[2 * vertex + 1] += lazy[vertex];
        lazy[vertex] = 0;
    }
    if(l > tr or r < tl)
        return LLONG_MAX;
    if(l >= tl and r <= tr)
        return val[vertex];
    int mid = (l + r) / 2;
    int res = get(2 * vertex, l, mid, tl, tr);
    return min(res, get(2 * vertex + 1, mid + 1, r, tl, tr));
}
