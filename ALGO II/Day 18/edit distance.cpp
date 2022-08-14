#define MAXN 500

int f[MAXN][MAXN];

int dp(int f[MAXN][MAXN], string& word1, string& word2, int n, int m, int k, int t) {
    if (k < 0)
        return t + 1;
    if (t < 0)
        return k + 1;
    if (f[k][t] != -1)
        return f[k][t];
    if (word1[k] == word2[t])
        return f[k][t] = dp(f, word1, word2, n, m, k - 1, t - 1);
    f[k][t] = max(n, m);
    f[k][t] = min(f[k][t], dp(f, word1, word2, n, m, k - 1, t - 1) + 1);
    f[k][t] = min(f[k][t], dp(f, word1, word2, n, m, k - 1, t) + 1);
    f[k][t] = min(f[k][t], dp(f, word1, word2, n, m, k, t - 1) + 1);
    return f[k][t];
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        memset(f, -1, sizeof(f));
        return dp(f, word1, word2, n, m, n - 1, m - 1);
    }
};