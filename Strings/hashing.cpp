long long compute_hash(string const& s) {
    const int p = 31; //needs to be prime just above no of characters
    const int m = 1e9 + 9; //needs to be a big prime
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m; //c-'a' cuz assuming c is a-z
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}


