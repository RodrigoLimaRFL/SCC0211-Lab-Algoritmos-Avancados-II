#include <iostream>
#include <vector>

using namespace std;

vector<int> calcularGrundy(int maxN, const vector<int>& possibilidades) {
    vector<int> grundy(maxN + 1, 0);

    for (int n = 1; n <= maxN; n++) {
        vector<bool> mex(possibilidades.size() + n + 1, false);

        for (int r : possibilidades) {
            if (n - r >= 0)
                mex[grundy[n - r]] = true;
        }

        int g = 0;
        while (mex[g]) g++;
        grundy[n] = g;
    }

    return grundy;
}


int main()
{
    int numPossibilidades;

    cin >> numPossibilidades;

    vector<int> possibilidadesDeRetirada(numPossibilidades);

    for(int i = 0; i < numPossibilidades; i++)
    {
        cin >> possibilidadesDeRetirada[i];
    }

    int numRodadas;

    cin >> numRodadas;

    vector<int> numPilhasPorRodada(numRodadas);
    vector<vector<int>> tamPilhasPorRodada(numRodadas);

    for(int i = 0; i < numRodadas; i++)
    {
        cin >> numPilhasPorRodada[i];

        tamPilhasPorRodada[i].resize(numPilhasPorRodada[i]);
        for(int j = 0; j < numPilhasPorRodada[i]; j++)
        {
            cin >> tamPilhasPorRodada[i][j];
        }
    }

    int maxTamPilhas = 0;

    for(const auto& pilhas : tamPilhasPorRodada)
    {
        for(int tam : pilhas)
        {
            if(tam > maxTamPilhas)
                maxTamPilhas = tam;
        }
    }

    vector<int> grundy = calcularGrundy(maxTamPilhas, possibilidadesDeRetirada);

    for(int i = 0; i < numRodadas; i++)
    {
        int nimSum = 0;

        for(int tam : tamPilhasPorRodada[i])
        {
            nimSum ^= grundy[tam];
        }

        if(nimSum != 0)
        {
            cout << "W";
        }
        else
        {
            cout << "L";
        }
    }
}