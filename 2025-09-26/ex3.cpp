#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int n = s1.size();
    int m = s2.size();
    int delta = 2; // inserção ou remoção

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // inicialização
    for(int i=0;i<=n;i++) dp[i][0] = i*delta;
    for(int j=0;j<=m;j++) dp[0][j] = j*delta;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1]; // mesmo caractere, custo 0
            } else {
                int costSub;
                if((isVowel(s1[i-1]) && isVowel(s2[j-1])) || 
                   (!isVowel(s1[i-1]) && !isVowel(s2[j-1]))){
                    costSub = 1; // substituição vogal-vogal ou consoante-consoante
                } else {
                    costSub = 3; // substituição vogal-consoante ou consoante-vogal
                }

                dp[i][j] = min({
                    dp[i-1][j] + delta,      // remoção
                    dp[i][j-1] + delta,      // inserção
                    dp[i-1][j-1] + costSub   // substituição
                });
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}
