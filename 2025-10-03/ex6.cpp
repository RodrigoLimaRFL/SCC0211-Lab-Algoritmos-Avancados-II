#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int menorCaminho(const vector<vector<int>> &distancias, int visitados, int pos)
{
    if (visitados == (1 << distancias.size()) - 1)
    {
        return 0;
    }

    if (dp[visitados][pos] != INT_MAX)
    {
        return dp[visitados][pos];
    }

    for (int i = 0; i < distancias.size(); i++)
    {
        if ((visitados & (1 << i)) == 0)
        {
            int novoCaminho = distancias[pos][i] + menorCaminho(distancias, visitados | (1 << i), i);
            dp[visitados][pos] = min(dp[visitados][pos], novoCaminho);
        }
    }

    return dp[visitados][pos];
}

int main()
{
    int n;

    cin >> n;

    vector<vector<int>> distancias(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> distancias[i][j];
        }
    }

    dp.resize(1 << n, vector<int>(n, INT_MAX));

    int menorInicio = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        menorInicio = min(menorInicio, menorCaminho(distancias, 1 << i, i));
    }

    cout << menorInicio << endl;

    return 0;
}