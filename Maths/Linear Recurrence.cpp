vector<int> combine (int n, vector<int> &a, vector<int> &b, vector<int> &tr) {
  vector<int> res(n * 2 + 1, 0);
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < n + 1; j++){
        res[i + j] += a[i] * b[j];
        res[i + j] %= MOD;
    }
  }
  for (int i = 2 * n; i > n; --i) {
    for (int j = 0; j < n; j++){
        res[i - 1 - j] += res[i] * tr[j];
        res[i - 1 - j] %= MOD;
    }
  }
  res.resize(n + 1);
  return res;
};
// transition -> for(i = 0; i < x; i++) f[n] += tr[i] * f[n-i-1]
// S contains initial values, k is 0 indexed
// LinearRecurrence returns f[k]
int LinearRecurrence(vector<int> &S, vector<int> &tr, long long k) {
  int n = S.size();
  if (n == 0) return 0;
  if (k < n) return S[k];
  vector<int> pol(n + 1), e(pol);
  pol[0] = e[1] = 1;
  for (++k; k; k /= 2) {
    if (k % 2) pol = combine(n, pol, e, tr);
    e = combine(n, e, e, tr);
  }
  int res = 0;
  for (int i = 0; i < n; i++){
    res += pol[i + 1] * S[i];
    res %= MOD;
  }
  return res;
}
