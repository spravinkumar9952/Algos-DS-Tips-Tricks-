long long mod_pow(long long a, long long b, long long m) {
    long long result = 1;
    a %= m; // Take mod first to avoid overflow

    while (b > 0) {
        if (b & 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b >>= 1; // Divide b by 2
    }

    return result;
}
