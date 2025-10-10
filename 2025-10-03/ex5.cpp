#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int menorCustoTarefas(const vector<vector<int>> &custoTarefas, int tarefasCompletas, int trabalhadorAtual)
{
    if (tarefasCompletas == (1 << custoTarefas.size()) - 1)
    {
        return 0;
    }

    if (dp[tarefasCompletas][trabalhadorAtual] != INT_MAX)
    {
        return dp[tarefasCompletas][trabalhadorAtual];
    }

    for (int i = 0; i < custoTarefas.size(); i++)
    {
        if ((tarefasCompletas & (1 << i)) == 0)
        {
            int novoCusto = custoTarefas[trabalhadorAtual][i] + menorCustoTarefas(custoTarefas, tarefasCompletas | (1 << i), trabalhadorAtual + 1);
            dp[tarefasCompletas][trabalhadorAtual] = min(dp[tarefasCompletas][trabalhadorAtual], novoCusto);
        }
    }

    return dp[tarefasCompletas][trabalhadorAtual];
}

int main()
{
    int n;

    cin >> n;

    vector<vector<int>> custoTarefas(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> custoTarefas[i][j];
        }
    }

    dp.resize(1 << n, vector<int>(n, INT_MAX));

    cout << menorCustoTarefas(custoTarefas, 0, 0) << endl;

    return 0;
}