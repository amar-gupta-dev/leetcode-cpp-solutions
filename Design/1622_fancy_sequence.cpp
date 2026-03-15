// Leetcode 1622
// Problem: fancy sequence
// Topic: design
// Diff: hard

class Fancy {
public:
    const long long MOD = 1e9 + 7;

    vector<long long> val, mulSnap, addSnap;
    long long mul = 1, add = 0;

    Fancy() {}

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    long long inv(long long x) {
        return modPow(x, MOD - 2);
    }

    void append(int v) {
        val.push_back(v);
        mulSnap.push_back(mul);
        addSnap.push_back(add);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= val.size()) return -1;

        long long v = val[idx];
        long long m = mul * inv(mulSnap[idx]) % MOD;

        long long result = (v * m) % MOD;
        result = (result + (add - addSnap[idx] * m % MOD + MOD) % MOD) % MOD;

        return result;
    }
};
