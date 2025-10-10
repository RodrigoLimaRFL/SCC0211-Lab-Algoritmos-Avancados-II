#include <bits/stdc++.h>
using namespace std;

// Função que calcula o tamanho da maior subsequência palindrômica
int longestPalindromicSubsequence(const string &s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // subsequência de tamanho 1 tem LPS = 1
    for(int i=0; i<n; i++) dp[i][i] = 1;

    // considerar substrings de tamanho 2 até n
    for(int len=2; len<=n; len++){
        for(int i=0; i<=n-len; i++){
            int j = i + len - 1;
            if(s[i] == s[j]){
                if(len == 2)
                    dp[i][j] = 2; // dois caracteres iguais
                else
                    dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // para consumir o \n após o número de casos
    while(T--){
        string s;
        getline(cin, s);
        cout << longestPalindromicSubsequence(s) << endl;
    }
    return 0;
}
