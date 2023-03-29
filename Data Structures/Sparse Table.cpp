template <class T>
struct RMQ { 
 
    long long n, mxlog;
    vector<vector<T>> rmq;
 
    void build(vector<T> &arr){
 
        n = arr.size();
        mxlog = 65 - __builtin_clzll(n);
        rmq.assign(n, vector<T>(mxlog));
        
        for(int i = 0; i < n; i++)
            rmq[i][0] = arr[i];
 
        for(int j = 1; j < mxlog; j++)
            for(int i = 0; i < n && i + (1LL << j) - 1 < n; i++)
                rmq[i][j] = min(rmq[i][j-1], rmq[i+(1LL<<(j-1))][j-1]);
 
    }
 
    T query(int l, int r){
        int lg = 63 - __builtin_clzll(r-l+1);
	    return min(rmq[l][lg], rmq[r-(1LL<<lg)+1][lg]);
    }
 
};

/*
RMQ<int> rmq;
rmq.build(arr);
rmq.query(l,r) [0 indexed]
*/
