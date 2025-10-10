#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numCombinacoes(const vector<int> &moedas, int valor)
{
    vector<long long int> dp(valor + 1, 0);
    dp[0] = 1; // Uma maneira de fazer o valor 0 (usando nenhuma moeda)

    for (int moeda : moedas)
    {
        for (int j = moeda; j <= valor; j++)
        {
            dp[j] += dp[j - moeda];
            dp[j] %= 1000000007;
        }
    }

    return dp[valor];
}

int main()
{
    int num_moedas;

    cin >> num_moedas;

    int valor;

    cin >> valor;

    vector<int> moedas(num_moedas);

    for (int i = 0; i < num_moedas; i++)
    {
        cin >> moedas[i];
    }

    cout << numCombinacoes(moedas, valor) << endl;

    return 0;
}