vector<vector<long long int> > multiply(vector<vector<long long int> >a, vector<vector<long long int> > b){
	vector<vector<long long> > ans(n, vector<long long int>(n, 0));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			for(int tt = 0; tt < n; ++tt)
				ans[i][j] = (ans[i][j] + (a[i][tt]*b[tt][j])) % MOD;
		}
	}
	return ans;
}

vector<vector<long long int> > matrix_exponentiation(vector<vector<long long int> >a, int k){
	vector<vector<long long int> > res(n, vector<long long int> (n, 0));
	for(int i = 0; i < n; ++i)
		res[i][i] = 1;
	while(k > 0){
		if(k % 2)
			res = multiply(res, a);
		a = multiply(a, a);
		k /= 2;
	}
	return res;
}
