#include <iostream>
#include <vector>

using namespace std;

bool primeiroJogadorVenceu(const vector<int>& tamPilhas, int numPilhas)
{
    int nimSum = 0;

    for(int i = 0; i < numPilhas; i++)
    {
        nimSum ^= (tamPilhas[i] % 4);
    }

    return nimSum != 0;
}

int main()
{
    int numRodadas;

    cin >> numRodadas;

    int pontuacaoPrimeiroJogador = 0;

    for(int i = 0; i < numRodadas; i++)
    {
        int numPilhas;

        cin >> numPilhas;

        vector<int> tamPilhas(numPilhas);

        for(int j = 0; j < numPilhas; j++)
        {
            cin >> tamPilhas[j];
        }

        if(primeiroJogadorVenceu(tamPilhas, numPilhas))
        {
            pontuacaoPrimeiroJogador++;
        }
        else
        {
            pontuacaoPrimeiroJogador--;
        }
    }

    cout << 20 + 20 * pontuacaoPrimeiroJogador << endl;

    return 0;
}